import pandas
from pandas.plotting import scatter_matrix


def assignment1():
    names = ["sepal-length", "sepal-width", "petal-length", "petal-width", "class"]
    data = pandas.read_csv("iris.csv", names=names)
    print(data.shape) # rows and columns are returned
    print(data.head(5)) #used to peak data
    print(data.describe()) # returns the standard descriptions
    print(data.groupby("class").size()) # classwise distribution of data
    
    data.plot(kind="box") # printing the box plot
    # matplotlib.pyplot.show() # using the show function to display the boxplot

    data.hist() # printing the histogram of the data
    # matplotlib.pyplot.show() # using the show function to display the boxplot
    
    scatter_matrix(data, alpha=0.8,diagonal="hist") # drawing the scatter matrix 
    # matplotlib.pyplot.show() # using the show function to display the boxplot
    
if __name__ == "__main__":
    assignment1()