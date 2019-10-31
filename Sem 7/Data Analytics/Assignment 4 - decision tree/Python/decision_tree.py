import numpy as np
import sklearn
import pandas as pd
from sklearn import metrics
from sklearn.metrics import accuracy_score
from sklearn.metrics import confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn import metrics
from sklearn.tree import  DecisionTreeClassifier

dataset = pd.read_csv("2010-capitalbikeshare-tripdata.csv")

X = np.asarray(dataset[['Duration', 'Start station number', 'End station number']])
Y = np.asarray(dataset['Member type'])

train_X, test_X, train_Y, test_Y = train_test_split(X, Y, test_size=0.20, shuffle= True)

decision_tree = DecisionTreeClassifier()
decision_tree.fit(train_X,train_Y)
y_predicted = decision_tree.predict(test_X)
accuracy = accuracy_score(y_predicted, test_Y)
accuracy *= 100
print('Accuracy of Decision Tree:', accuracy)
print("classification report is...")
print(metrics.classification_report(test_Y, y_predicted))
print("confusion matrix is...")
print(metrics.confusion_matrix(test_Y, y_predicted))


