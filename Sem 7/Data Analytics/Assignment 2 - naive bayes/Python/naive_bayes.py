import sklearn
import pandas as pd
from sklearn import metrics
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.naive_bayes import GaussianNB

dataset = pd.read_csv("PimaIndiansDiabetes.csv")
train, test = train_test_split(dataset, test_size=0.20)
train_X = train[train.columns[:8]]
test_X = test[test.columns[:8]]
train_Y = train['Class']
test_Y = test['Class']

gaussianNB = GaussianNB()
gaussianNB.fit(train_X, train_Y)
y_predicted = gaussianNB.predict(test_X)
accuracy = accuracy_score(y_predicted, test_Y)
accuracy *= 100
print('Accuracy of Naive Bayes:', accuracy)
print("classification report is...")
print(metrics.classification_report(test_Y, y_predicted))
print("confusion matrix is...")
print(metrics.confusion_matrix(test_Y, y_predicted))