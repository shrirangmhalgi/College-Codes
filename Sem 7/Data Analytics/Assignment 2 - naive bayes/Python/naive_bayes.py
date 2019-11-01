import pandas as pandas
from sklearn.metrics import confusion_matrix
from sklearn.metrics import classification_report
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB

def assignment2():
    data = pandas.read_csv("PimaIndiansDiabetes.csv") # reading the dataset
    data.hist()
    data.plot(kind="box")
    
    print(data.shape) # rows and columns are returned
    print(data.head(5)) #used to peak data
    print(data.describe()) # returns the standard descriptions
    
    train_set, test_set = train_test_split(data, test_size=0.20, shuffle = True) # spliting the dataset
    
    # train_X = train_set[[train_set.columns[0], train_set.columns[1]]] # 1st 8 columns are attributes for training
    train_X = train_set[train_set.columns[:8]] # 1st 8 columns are attributes for training
    train_Y = train_set[train_set.columns[-1]] # last column is for prediction
    test_X = test_set[test_set.columns[:8]] # 1st 8 columns are attributes for testing
    test_Y = test_set[test_set.columns[-1]] # last column is for prediction
    
    naive_bayes = GaussianNB() # creating object of GaussianNB
    naive_bayes.fit(train_X, train_Y) # trainng the model
    predicted_Y = naive_bayes.predict(test_X) # getting the test result
    
    accuracy = accuracy_score(predicted_Y, test_Y) # calculating the accuracy
    accuracy *= 100 # getting the accuracy percentage
    print(f"accuracy of Naive Bayes is {accuracy}") # printing the accuracy of Naive Bayes
    print(f"classification report is") # printing the classification report
    print(classification_report(test_Y, predicted_Y)) # printing the classification report
    print("confusion matrix is") # printing the confusion matrix
    print(confusion_matrix(test_Y, predicted_Y)) # printing the confusion matrix

if __name__ == "__main__":
    assignment2()