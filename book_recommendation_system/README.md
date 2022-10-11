## Project to Build a Book Recommendation System 

This project is to build a book recommendation system using the [Goodreads](https://www.goodreads.com/) dataset. The dataset is available on [Kaggle](https://www.kaggle.com/jealousleopard/goodreadsbooks).

## Index

- [Project to Build a Book Recommendation System](#project-to-build-a-book-recommendation-system)
- [Index](#index)
- [Folder Structure](#folder-structure)
- [Data](#data)
- [Data Cleaning](#data-cleaning)
- [Top Books](#top-books)
- [Implementing kNN](#implementing-knn)
- [Implementing SVD](#implementing-svd)
- [Backend API Routes](#backend-api-routes)
- [Frontend](#frontend)
- [Running the app](#running-the-app)
- [Refrences](#refrences)
- [Contributors](#contributors)


## Folder Structure

```
├── README.md # The top-level README for developers using this project.
├── Book # Folder for the book CSV files
│   ├── Books.csv # Book details
│   ├── Books(explicit).csv # Book details with explicit ratings
│   ├── Ratings.csv # Ratings given by users
│   ├── Users.csv # User details
├──static # Folder for static files
│   ├── css # Folder for CSS files
│   │   ├── bootstrap.min.css
│   │   ├── style.css
│   │   ├── bootstrap.css
│   │   ├── bootstrap-grid.css
│   │   ├── bootstrap-grid.min.css
│   │   ├── bootstrap-reboot.css
│   ├── datatables # Folder for datatables files
│   │   ├── dataTables.bootstrap4.css
│   │   ├── dataTables.bootstrap4.min.css
│   │   ├── dataTables.bootstrap.css 
│   │   ├── dataTables.bootstrap.min.css
│   │   ├── jquery.dataTables.css
│   │   ├── jquery.dataTables.min.css 
│   ├── externalCss # Folder for external CSS files
│   │   ├── registation.css
│   ├── fontawesome-free # Folder for fontawesome files
├── templates # Folder for HTML files 
│   ├── index.html
│   ├── result.html
│   ├── svd.html
│   ├── resultSvd.html
├── app.py # Flask app and backend API
├── .gitattributes

```

## Data

The dataset is available on [Kaggle](https://www.kaggle.com/jealousleopard/goodreadsbooks). The dataset contains 5 CSV files. The files are as follows:

- Books.csv: Contains book details
- Books(explicit).csv: Contains book details with explicit ratings
- Ratings.csv: Contains ratings given by users
- Users.csv: Contains user details

- Dataset columns:
  
    - Books.csv: ISBN,bookTitle,bookAuthor,yearOfPublication,publisher
    - Books(explicit).csv: ISBN,bookTitle,bookAuthor,yearOfPublication,publisher
    - Ratings.csv: userID,ISBN,bookRating
    - Users.csv: userID, location, age

## Data Cleaning

- The dataset contains a lot of missing values. The missing values are replaced with the mean of the column. The dataset is also normalized to remove the bias in the dataset. Splitting has been done on Explicit and Implicit user ratings to build the recommendation system.
- Ratings.csv: Contains ratings given by users. Here we are removing the rows which are having rating 0. This is because the rating 0 is not given by the user. It is given by the system to indicate that the user has not rated the book. So we are removing the rows which are having rating 0.
- Then for each book we are calculating the average rating and the number of ratings. We are also calculating the number of ratings for each user. We are also calculating the average rating for each user.
- To get a stronger similarity between the books, we are removing the books which are having less than 50 ratings and the users who are having less than 50 ratings.
- Generating the unique books and ISBNs list. 

## Top Books 

- The top books are calculated based on the average rating of the books. The top 10 books are displayed in the index page. The top 10 books are also displayed in the result page.
- Here we are specifying the latency of meanRating with value of 3 and latency of ratingCount with value of 50. This is because we are removing the books which are having less than 50 ratings. So we are specifying the latency of ratingCount with value of 50. We are also specifying the latency of meanRating with value of 3. This is because we are removing the books which are having average rating less than 3. So we are specifying the latency of meanRating with value of 3.

## Implementing kNN

- KNN is implemented using the cosine similarity. The cosine similarity is calculated between the books. The books which are having the highest cosine similarity are recommended to the user. The top 10 books are recommended to the user. The top 10 books are also displayed in the result page.
- Implementing kNN: In numerical analysis and scientific computing, a sparse matrix or sparse array is a matrix in which
most of the elements are zero. We convert our table to a 2D matrix, and fill the missing values with zeros (since we will calculate distances between rating vectors). We then transform the values(ratings) of the matrix dataframe into a scipy sparse matrix for more efficient calculations. Finding the Nearest Neighbors We use unsupervised algorithms with sklearn.neighbors. The algorithm we use to compute the nearest neighbors is “brute”, and we specify “metric=cosine” algorithm will calculate the cosine similarity between rating vectors. Finally, we fit the model.
- The cosine similarity is calculated between the books. The books which are having the highest cosine similarity are recommended to the user. The top 10 books are recommended to the user. The top 10 books are also displayed in the result page.
  

## Implementing SVD

- SVD is singular value decomposition which is implemented using the Scipy SVD library. The Scipy SVD library is used to decompose the matrix into 3 matrices. The top 10 books are recommended to the user. The top 10 books are also displayed in the result page. 

- Implementing SVD: In numerical analysis and scientific computing, a sparse matrix or sparse array is a matrix in which most of the elements are zero. We convert our table to a 2D matrix, and fill the missing values with zeros (since we will calculate distances between rating vectors). We then transform the values(ratings) of the matrix dataframe into a scipy sparse matrix for more efficient calculations. Finding the Nearest Neighbors We use unsupervised algorithms with sklearn.neighbors. The algorithm we use to compute the nearest neighbors is “brute”, and we specify “metric=cosine” algorithm will calculate the cosine similarity between rating vectors. Finally, we fit the model.

## Backend API Routes

- Two backend API routes are implemented. The first API route is for the kNN algorithm. The second API route is for the SVD algorithm. The API routes are implemented using the Flask framework. The API routes are as follows:
  - /predict: This API route is for the kNN algorithm. This API route takes the book title as the input and returns the top 10 recommended books.
  - /svd: This API route is for the SVD algorithm. This API route takes the book title as the input and returns the top 10 recommended books.
- Routes are defined in the app.py file. The routes are defined as follows:
  - @app.route('/predict', methods=['POST'])
  - @app.route('/svd', methods=['POST'])


## Frontend

- Tech stack: HTML, CSS, Bootstrap, JavaScript, jQuery, DataTables, Font Awesome 
- Various HTML files are used to implement the frontend. The HTML files are as follows:
  - index.html: This HTML file is used to display the top 10 books in the index page. This HTML file is also used to display the top 10 books in the result page.
  - result.html: This HTML file is used to display the top 10 recommended books in the result page.
  - svd.html: This HTML file is used to display the top 10 recommended books in the result page.
  - resultSvd.html: This HTML file is used to display the top 10 recommended books in the result page.


## Running the app

- Clone the repository
- Install the requirements using the command: pip install -r requirements.txt
- Set the FLASK_APP environment variable: export FLASK_APP=app.py
- Start the Flask server: flask run
- Run the app on http://localhost:5000/


## Refrences

- [Goodreads Books Dataset](https://www.kaggle.com/jealousleopard/goodreadsbooks)
- [Python](https://www.python.org/)
- [Flask](https://flask.palletsprojects.com/en/1.1.x/)
- [KNN](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm)
- [SVD](https://en.wikipedia.org/wiki/Singular_value_decomposition)
- [Cosine Similarity](https://en.wikipedia.org/wiki/Cosine_similarity)
- [Recommendation System](https://en.wikipedia.org/wiki/Recommender_system)

## Contributors

- [Aditya Raj](https://www.linkedin.com/in/gnsaddy/)

