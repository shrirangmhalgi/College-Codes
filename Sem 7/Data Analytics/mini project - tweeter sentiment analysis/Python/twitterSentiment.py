import sys, tweepy
from textblob import TextBlob
import matplotlib.pyplot as plt

def percentage(part, whole):
    return (100 * float(part) / float(whole))

def main():
    consumer_key = '1Zhm0krQV7hiP1fWnyYH5IZlx'
    consumer_secret = 'Pkyj4LbbNH4r2B9NJgWo1xFIbLv7nsCcJr6X18RwhqtfCIGj3N'

    access_token = '979802802364051456-Oo2zhibedp4EeBtzupxf7XBVeAM45br'
    access_token_secret = '3VrSDugBiQv1gV6a9mdFieSrEPRzijCOGcLlH10MOV5HI'

    auth =  tweepy.OAuthHandler(consumer_key, consumer_secret)
    auth.set_access_token(access_token, access_token_secret)

    api = tweepy.API(auth)

    searchTerm = input('Enter the term/hashtag to search about: ')
    noOfSearchTerms = int(input('Enter how many Tweets to analyze: '))
    tweets = tweepy.Cursor(api.search, q = searchTerm, lang = 'en').items(noOfSearchTerms)

    positive = 0
    weaklyPositive = 0
    stronglyPositive = 0
    negative = 0
    weaklyNegative = 0
    stronglyNegative = 0
    neutral = 0
    polarity = 0

    for tweet in tweets:
        print(tweet)
        analysis = TextBlob(tweet.text)
        polarity += analysis.sentiment.polarity

        if (analysis.sentiment.polarity == 0):
            neutral += 1
        elif (analysis.sentiment.polarity > 0 and analysis.sentiment.polarity <= 0.3):
            weaklyPositive += 1
        elif (analysis.sentiment.polarity > 0.3 and analysis.sentiment.polarity <= 0.6):
            positive += 1
        elif (analysis.sentiment.polarity > 0.6 and analysis.sentiment.polarity <= 1):
            stronglyPositive += 1
        elif (analysis.sentiment.polarity > -0.3 and analysis.sentiment.polarity <= 0):
            weaklyNegative += 1
        elif (analysis.sentiment.polarity > -0.6 and analysis.sentiment.polarity <= -0.3):
            negative += 1
        elif (analysis.sentiment.polarity > -1 and analysis.sentiment.polarity <= -0.6):
            stronglyNegative += 1
    
    positive = percentage(positive, noOfSearchTerms)
    weaklyPositive = percentage(weaklyPositive, noOfSearchTerms)
    stronglyPositive = percentage(stronglyPositive, noOfSearchTerms)
    negative = percentage(negative, noOfSearchTerms)
    weaklyNegative = percentage(weaklyNegative, noOfSearchTerms)
    stronglyNegative = percentage(stronglyNegative, noOfSearchTerms)
    neutral = percentage(neutral, noOfSearchTerms)
    polarity = percentage(polarity, noOfSearchTerms)

    # Average reaction
    polarity = polarity / noOfSearchTerms

    print('How many people are reacting to ' + searchTerm + ' by analyzing ' + str(noOfSearchTerms) + ' Tweets')

    if (polarity == 0):
        print("Neutral")
    elif (polarity > 0 and polarity <= 0.3):
        print("Weakly Positive")
    elif (polarity > 0.3 and polarity <= 0.6):
        print("Positive")
    elif (polarity > 0.6 and polarity <= 1):
        print("Strongly Positive")
    elif (polarity > -0.3 and polarity <= 0):
        print("Weakly Negative")
    elif (polarity > -0.6 and polarity <= -0.3):
        print("Negative")
    elif (polarity > -1 and polarity <= -0.6):
        print("Strongly Negative")
    
    print("Detailed Report: ")
    print(str(positive) + "% people thought it was positive")
    print(str(weaklyPositive) + "% people thought it was weakly positive")
    print(str(stronglyPositive) + "% people thought it was strongly positive")
    print(str(negative) + "% people thought it was negative")
    print(str(weaklyNegative) + "% people thought it was weakly negative")
    print(str(stronglyNegative) + "% people thought it was strongly negative")
    print(str(neutral) + "% people thought it was neutral")

    labels = ['Positive [' + str(positive) + '%]', 'Weakly Positive [' + str(weaklyPositive) + '%]', 'Strongly Positive [' + str(stronglyPositive) + '%]', 'Neutral [' + str(neutral) + '%]',
              'Negative [' + str(negative) + '%]', 'Weakly Negative [' + str(weaklyNegative) + '%]', 'Strongly Negative [' + str(stronglyNegative) + '%]']
    sizes = [positive, weaklyPositive, stronglyPositive,
             neutral, negative, weaklyNegative, stronglyNegative]
    colors = ['yellowgreen', 'lightgreen', 'darkgreen',
              'gold', 'red', 'lightsalmon', 'darkred']
    patches, texts = plt.pie(sizes, colors=colors, startangle=90)
    plt.legend(patches, labels, loc="best")
    plt.title('How people are reacting on ' + searchTerm +
              ' by analyzing ' + str(noOfSearchTerms) + ' Tweets.')
    plt.axis('equal')
    plt.tight_layout()
    plt.show()


if __name__ == '__main__':
    main()
