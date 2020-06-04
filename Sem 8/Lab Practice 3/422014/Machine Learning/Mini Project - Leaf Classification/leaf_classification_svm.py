import pandas as pd
import matplotlib.pyplot as plt
import warnings
import seaborn as sns
import pylab as pl
from matplotlib import cm
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
from sklearn.svm import SVC
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix


warnings.filterwarnings('always')

leaf = pd.read_csv('leaf.csv') # Loading the dataset
leaf.head() # showing top 10 rows

print(leaf.shape) # rows and columns

print(leaf['Specimen'].unique()) # printing unique specimens

print(leaf.groupby('Specimen').size()) # performing aggregation results on each specimen

sns.countplot(leaf['Specimen'],label="Count") # plotting the count of each specimen
plt.savefig('count_leaf') # saving the plot
plt.show() # displaying the plot

leaf.drop('Class' ,axis=1).hist(bins=30, figsize=(9,9)) # drawing histogram for each feature attribute
pl.suptitle("Histogram for each numeric input variable") # giving title for the histogram
plt.savefig('leaf_hist') # saving the plot
plt.show() # displaying the plot

# features of the dataset
feature_names =["Eccentricity",
                "Elongation",
                "Solidity",
                "Stochastic_convexity",
                "Lobedness",
                "Avd_intensity",
                "Avg_contrast",
                "smoothness",
                "Third_moment",
                "Uniformity",
                "Entropy"]

X = leaf[feature_names] # creating the X variable for graph
y = leaf['Class'] # creating the Y variable for graph
cmap = cm.get_cmap('gnuplot') # creating the gnu plot
scatter = pd.plotting.scatter_matrix(X, c = y, marker = 'o', s=40, hist_kwds={'bins':15}, figsize=(9,9), cmap = cmap) # creating the scatterplot
plt.suptitle('Scatter-matrix for each input variable') # giving title for graph
plt.savefig('leaf_scatter_matrix') # saving the plot
plt.show() # displaying the plot

X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0) # creating the training and testing set
scaler = MinMaxScaler() # used to scale the values
X_train = scaler.fit_transform(X_train) # fits and transforms into the range
X_test = scaler.transform(X_test) # transforms into the range

svm = SVC() # creating object of Support Vector Classifier
svm.fit(X_train, y_train) # fitting the model
print('Accuracy of SVM classifier on training set: {:.2f}'.format(svm.score(X_train, y_train))) # printing the accuracy of svm on train set
print('Accuracy of SVM classifier on test set: {:.2f}'.format(svm.score(X_test, y_test))) # printing the accuracy of svm on test set


pred = svm.predict(X_test) # predicting the results
print(confusion_matrix(y_test, pred)) # printing the connfusion matrix
print(classification_report(y_test, pred)) # printing the classification report
