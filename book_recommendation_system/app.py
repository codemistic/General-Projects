from flask import Flask, render_template, url_for, request
import pandas as pd
from scipy.sparse import csr_matrix
from scipy.sparse.linalg import svds
import numpy as np
from sklearn.neighbors import NearestNeighbors

app = Flask(__name__)


@app.route('/')
def home():
    return render_template('home.html')


@app.route('/svdIndex')
def svdIndex():
    return render_template('svd.html')


class Books:
    def __init__(self):
        self.books = pd.read_csv('./Book/Books.csv')
        self.users = pd.read_csv('./Book/Users.csv')
        self.ratings = pd.read_csv('./Book/Ratings.csv')

        # Splitting Explicit and Implicit user ratings
        # we are removing the rating set which is having the rating as 0
        self.ratings_explicit = self.ratings[self.ratings.bookRating != 0]
        self.ratings_implicit = self.ratings[self.ratings.bookRating == 0]

        # Each Books Mean ratings and Total Rating Count
        self.average_rating = pd.DataFrame(
            self.ratings_explicit.groupby('ISBN')['bookRating'].mean())
        self.average_rating['ratingCount'] = pd.DataFrame(
            self.ratings_explicit.groupby('ISBN')['bookRating'].count())
        self.average_rating = self.average_rating.rename(
            columns={'bookRating': 'MeanRating'})

        # To get a stronger similarities
        counts1 = self.ratings_explicit['userID'].value_counts()
        self.ratings_explicit = self.ratings_explicit[
            self.ratings_explicit['userID'].isin(counts1[counts1 >= 50].index)]

        # Explicit Books and ISBN
        self.explicit_ISBN = self.ratings_explicit.ISBN.unique()
        self.explicit_books = self.books.loc[self.books['ISBN'].isin(
            self.explicit_ISBN)]

        # Look up dict for Book and BookID
        self.Book_lookup = dict(
            zip(self.explicit_books["ISBN"], self.explicit_books["bookTitle"]))
        self.ID_lookup = dict(
            zip(self.explicit_books["bookTitle"], self.explicit_books["ISBN"]))

    def Top_Books(self, n=10, RatingCount=100, MeanRating=3):
        # here we are specifying the latency of meanRating with value of 3
        # and latency of RatingCount with value of 100
        # this makes a threshold value for predicting the best possible book sets for the user
        # books with the highest rating
        # this function will not recommend any books just shows the highest rated books rated by every user
        BOOKS = self.books.merge(self.average_rating, how='right', on='ISBN')
        # print(Books)
        M_Rating = BOOKS.loc[BOOKS.ratingCount >= RatingCount].sort_values(
            'MeanRating', ascending=False).head(n)

        H_Rating = BOOKS.loc[BOOKS.MeanRating >= MeanRating].sort_values(
            'ratingCount', ascending=False).head(n)

        # print(M_Rating)
        # print(H_Rating)

        return M_Rating, H_Rating


class KNN(Books):

    def __init__(self, n_neighbors=5):
        # calling super class __init__ method
        super().__init__()
        # assigning k  value = 5
        self.n_neighbors = n_neighbors
        # removing nan value
        self.ratings_mat = self.ratings_explicit.pivot(
            index="ISBN", columns="userID", values="bookRating").fillna(0)
        '''
        Implementing kNN
        In numerical analysis and scientific computing, a sparse matrix or sparse array is a matrix in which
        most of the elements are zero.
        We convert our table to a 2D matrix, and fill the missing values with zeros 
        (since we will calculate distances between rating vectors). We then transform the values(ratings)
        of the matrix dataframe into a scipy sparse matrix for more efficient calculations.
        Finding the Nearest Neighbors We use unsupervised algorithms with sklearn.neighbors.
        The algorithm we use to compute the nearest neighbors is “brute”, and we specify “metric=cosine” 
        algorithm will calculate the cosine similarity between rating vectors. Finally, we fit the model.
        '''
        self.uti_mat = csr_matrix(self.ratings_mat.values)
        # KNN Model Fitting
        # KNN Model Fitting
        # using cosine similarity
        '''Mathematically, it measures 
        the cosine of the angle between two vectors projected in a multi-dimensional space
        Cosine similarity is a metric used to determine how
         similar the documents are irrespective of their size.'''
        self.model_knn = NearestNeighbors(metric='cosine', algorithm='brute')
        self.model_knn.fit(self.uti_mat)

    def Recommend_Books(self, book, n_neighbors=5):
        # Book Title  to BookID
        # bID = list(self.Book_lookup.keys())[list(self.Book_lookup.values()).index(book)]
        bID = self.ID_lookup[book]

        query_index = self.ratings_mat.index.get_loc(bID)

        KN = self.ratings_mat.iloc[query_index, :].values.reshape(1, -1)

        distances, indices = self.model_knn.kneighbors(
            KN, n_neighbors=n_neighbors + 1)

        Rec_books = list()
        Book_dis = list()

        for i in range(1, len(distances.flatten())):
            Rec_books.append(self.ratings_mat.index[indices.flatten()[i]])
            Book_dis.append(distances.flatten()[i])

        Book = self.Book_lookup[bID]

        Recommmended_Books = self.books[self.books['ISBN'].isin(Rec_books)]

        return Book, Recommmended_Books, Book_dis


# -----------------------------------------------------------------------------------------------------
class SVD(Books):

    def __init__(self, n_latent_factor=50):
        super().__init__()
        self.n_latent_factor = n_latent_factor
        self.ratings_mat = self.ratings_explicit.pivot(
            index="userID", columns="ISBN", values="bookRating").fillna(0)

        self.uti_mat = self.ratings_mat.values
        # normalize by each users mean
        self.user_ratings_mean = np.mean(self.uti_mat, axis=1)
        self.mat = self.uti_mat - self.user_ratings_mean.reshape(-1, 1)

        self.explicit_users = np.sort(self.ratings_explicit.userID.unique())
        self.User_lookup = dict(
            zip(range(1, len(self.explicit_users)), self.explicit_users))

        self.predictions = None

    def scipy_SVD(self):
        # singular value decomposition
        U, S, Vt = svds(self.mat, k=self.n_latent_factor)

        S_diag_matrix = np.diag(S)

        # Reconstructing Original Prediction Matrix
        X_pred = np.dot(np.dot(U, S_diag_matrix), Vt) + \
                 self.user_ratings_mean.reshape(-1, 1)

        self.predictions = pd.DataFrame(
            X_pred, columns=self.ratings_mat.columns, index=self.ratings_mat.index)

        return

    def Recommend_Books(self, userID, num_recommendations=5):
        # Get and sort the user's predictions
        # User ID starts at 1, not 0
        user_row_number = self.User_lookup[userID]

        sorted_user_predictions = self.predictions.loc[user_row_number].sort_values(
            ascending=False)

        # Get the user's data and merge in the books information.
        user_data = self.ratings_explicit[self.ratings_explicit.userID == (
            self.User_lookup[userID])]
        user_full = (user_data.merge(self.books, how='left', left_on='ISBN', right_on='ISBN').
                     sort_values(['bookRating'], ascending=False)
                     )

        # Recommend the highest predicted rating books that the user hasn't seen yet.
        recom = (self.books[~self.books['ISBN'].isin(user_full['ISBN'])].
                 merge(pd.DataFrame(sorted_user_predictions).reset_index(), how='left',
                       left_on='ISBN',
                       right_on='ISBN'))
        recom = recom.rename(columns={user_row_number: 'Predictions'})
        recommend = recom.sort_values(by=['Predictions'], ascending=False)
        recommendations = recommend.iloc[:num_recommendations, :-1]

        return user_full, recommendations


@app.route('/predict', methods=['POST'])
def predict():
    global KNN_Recommended_Books
    if request.method == 'POST':
        ICF = KNN()
        book = request.form['book']
        data = book

        _, KNN_Recommended_Books, _ = ICF.Recommend_Books(data)

        KNN_Recommended_Books = KNN_Recommended_Books.merge(
            ICF.average_rating, how='left', on='ISBN')
        KNN_Recommended_Books = KNN_Recommended_Books.rename(
            columns={'bookRating': 'MeanRating'})

        df = pd.DataFrame(KNN_Recommended_Books, columns=['bookTitle', 'bookAuthor', 'MeanRating'])

    return render_template('result.html', predictionB=KNN_Recommended_Books[['bookTitle']],
                           predictionA=KNN_Recommended_Books[['bookAuthor']],
                           predictionR=KNN_Recommended_Books[['MeanRating']],
                           prediction=df)


@app.route('/svd', methods=['POST'])
def svd():
    global SVD_Recommended_Books
    if request.method == 'POST':
        userCollaborativeFiltering = SVD()
        userCollaborativeFiltering.scipy_SVD()
        userId = request.form['svd']
        data = int(userId)

        Rated_Books, SVD_Recommended_Books = userCollaborativeFiltering.Recommend_Books(
            userID=data)

        pd.set_option('display.max_colwidth', -1)

        SVD_Recommended_Books = SVD_Recommended_Books.merge(
            userCollaborativeFiltering.average_rating, how='left', on='ISBN')
        SVD_Recommended_Books = SVD_Recommended_Books.rename(
            columns={'bookRating': 'MeanRating'})

        lst = list(SVD_Recommended_Books[['bookTitle', 'bookAuthor', 'bookAuthor']])
        print(lst)
        for k in lst:
            print(k)

    return render_template('resultSvd.html', predictionB=SVD_Recommended_Books[['bookTitle']],
                           predictionA=SVD_Recommended_Books[['bookAuthor']],
                           predictionR=SVD_Recommended_Books[['MeanRating']],
                           prediction=SVD_Recommended_Books)


if __name__ == '__main__':
    app.run(debug=True)
