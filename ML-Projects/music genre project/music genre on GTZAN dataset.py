import os
import pandas as pd
import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt
%matplotlib inline
import sklearn
import math

import librosa
import librosa.display

from sklearn.naive_bayes import GaussianNB
from sklearn.linear_model import SGDClassifier, LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC
from sklearn.neural_network import MLPClassifier
from xgboost import XGBClassifier, XGBRFClassifier
from xgboost import plot_tree, plot_importance

from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score, roc_auc_score, roc_curve
from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from sklearn.feature_selection import RFE


import warnings
warnings.filterwarnings('ignore')

path='../input/gtzan-dataset-music-genre-classification/Data'
genres=os.listdir(os.path.join(path,'genres_original/'))
print(genres)

y,sr= librosa.load(os.path.join(path,'genres_original','classical','classical.00001.wav'))
print("y=",y,'\n')
print("Sample rate",sr,'\n')
print("Duration :",y.shape[0]/sr)

# trimming the silence in the audio 
audio,_=librosa.effects.trim(y)
print("y: ",y,'\n')
print('Duration :',audio.shape[0]/sr)

plt.figure(figsize=(10,5))
librosa.display.waveshow(y=audio,sr=sr,color='b')
plt.title("Classical I")

for i in genres:
    aud,sr=librosa.load(os.path.join(path,'genres_original',i,f'{i}.00001.wav'))
    plt.figure(figsize=(10,4))
    librosa.display.waveshow(y=aud,sr=sr,color='b')
    plt.title(f'{i}')
    
 n_fft=2048 #default value recommended, n_ftt represents the number of samples that will be converted at once.
hop_length=512 #understandable by name
win_length=2048 #window using which samples are converted.

for i in genres:
    aud,sr=librosa.load(os.path.join(path,'genres_original',i,f'{i}.00001.wav'))
    aud_ft= np.abs(librosa.stft(aud, n_fft = n_fft, hop_length = hop_length,win_length=win_length))
#     print(np.shape(aud_ft)) #(1025,1302) 
    plt.figure(figsize=(12,4))
    plt.plot(aud_ft[:500,:])#viewing only upto 500 Hz
    plt.title(f'{i}')
    
music_stft = np.abs(librosa.stft(audio,n_fft=n_fft,hop_length= hop_length))
plt.figure(figsize = (16,6))
plt.plot(music_stft);

data=pd.read_csv(os.path.join(path,'features_30_sec.csv'))
data.head()
data.columns
data.describe()

from sklearn import preprocessing
data=data.iloc[0:,2:]
Y=data.loc[:,'label']
X=data.loc[:,data.columns!='label']

cols=X.columns
min_max_scaler=preprocessing.MinMaxScaler()
scaled_X=min_max_scaler.fit_transform(X) #the column names are removed
X=pd.DataFrame(scaled_X,columns=cols)

from sklearn.decomposition import PCA
n=10
pca=PCA(n_components=n)
pc=pca.fit_transform(X)
col_names=[f'PC{i}' for i in range(1,n+1)]
data_X=pd.DataFrame(data=pc,columns=col_names)

final_df=pd.concat([data_X,Y],axis=1)
final_df.head()
plt.figure(figsize = (16, 11))
sns.scatterplot(x = "PC1", y = "PC2", data = final_df, hue = "label", alpha = 0.7,
               s = 100);

plt.title('PCA on Genres', fontsize = 24)
plt.xticks(fontsize = 14)
plt.yticks(fontsize = 10);
plt.xlabel("Principal Component 1", fontsize = 14)
plt.ylabel("Principal Component 2", fontsize = 14)


data= pd.read_csv(os.path.join(path,'features_3_sec.csv'))
data.head()
data.columns
data.describe()
data=data.iloc[0:,2:]
Y=data.loc[:,'label']
X=data.loc[:,data.columns!='label']

cols=X.columns

scaler=preprocessing.MinMaxScaler()
scaled_X=scaler.fit_transform(X)

X=pd.DataFrame(scaled_X,columns=cols)
X_train,X_test,y_train,y_test=train_test_split(X,Y,test_size=0.3,random_state=21)
def model_assess(model,title):
    model.fit(X_train,y_train)
    preds=model.predict(X_test)
    print('Accuracy', title, ':', round(accuracy_score(y_test, preds), 5), '\n')
    
# Naive Bayes
nb = GaussianNB()
model_assess(nb, "Naive Bayes")

# Stochastic Gradient Descent
sgd = SGDClassifier(max_iter=5000, random_state=0)
model_assess(sgd, "Stochastic Gradient Descent")

# KNN
knn = KNeighborsClassifier(n_neighbors=19)
model_assess(knn, "KNN")

# Decission trees
tree = DecisionTreeClassifier()
model_assess(tree, "Decission trees")

# Random Forest
rforest = RandomForestClassifier(n_estimators=1000, max_depth=10, random_state=0)
model_assess(rforest, "Random Forest")

# Support Vector Machine
svm = SVC(decision_function_shape="ovo")
model_assess(svm, "Support Vector Machine")

# Logistic Regression
lg = LogisticRegression(random_state=0, solver='lbfgs', multi_class='multinomial')
model_assess(lg, "Logistic Regression")

# Neural Nets
nn = MLPClassifier(solver='lbfgs', alpha=1e-5, hidden_layer_sizes=(5000, 10), random_state=1)
model_assess(nn, "Neural Nets")
le=LabelEncoder()
labels=le.fit_transform(Y)
X_train,X_test,y_train,y_test=train_test_split(X,labels,test_size=0.3,random_state=21)


# Cross Gradient Booster
xgb = XGBClassifier(n_estimators=1000, learning_rate=0.05)
xgb.fit(X_train,y_train)
preds=xgb.predict(X_test)
print('Accuracy',"xgb", ':', round(accuracy_score(y_test, preds), 5), '\n')


# Cross Gradient Booster (Random Forest)
xgbrf = XGBRFClassifier(objective= 'multi:softmax')
xgbrf.fit(X_train,y_train)
preds=xgbrf.predict(X_test)
print('Accuracy',"xgbrf", ':', round(accuracy_score(y_test, preds), 5), '\n')

#improving xgb gradient booster
xgb1=XGBClassifier(n_estimators=1400,learning_rate=0.03)
xgb1.fit(X_train,y_train)
preds=xgb1.predict(X_test)
print('Accuracy',"xgb1", ':', round(accuracy_score(y_test, preds), 5), '\n')
