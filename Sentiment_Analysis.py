#Author = Sitam Meur.
#Topic = 'Twitter Sentiment Analysis'.
#Technologies = 'tweepy' and 'TextBlob' Python Library.


import tweepy
from textblob import TextBlob

# Step 1 - Authenticate

API_key = 'Your API key here'
API_key_secret = 'Your API key secret here'

Access_token ='Access Token here'
Access_token_secret = 'Access Token Secret here'

auth = tweepy.OAuthHandler(API_key, API_key_secret)
auth.set_access_token(Access_token, Access_token_secret)

api = tweepy.API(auth)

# Step 2 - Retrieve Tweets

public_tweets = api.search_tweets('Ronaldo')

# Step 3 - Main Script

for tweet in public_tweets:
    print(tweet.text)
    analysis = TextBlob(tweet.text)
    print(analysis.sentiment)
    print("")

