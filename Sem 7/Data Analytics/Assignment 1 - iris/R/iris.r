# Download the Iris flower dataset or any other dataset into a DataFrame. 
# (eg  https://archive.ics.uci.edu/ml/datasets/Iris ) 
# Use Python/R and Perform following
# How many features are there and what are their types (e.g., numeric, nominal)? 
# Compute and display summary statistics for each feature available in the dataset. (eg. minimum value, maximum value, mean, range, standard deviation, variance  and percentiles) 
# Data Visualization-Create a histogram for each feature in the dataset to illustrate the feature distributions. Plot each histogram.  
# Create a boxplot for each feature in the dataset.  All of the boxplots should be combined into a single plot.  Compare distributions and identify outliers.


library(datasets) #import the system default libraries.
head(iris) #view the first 6 values of the dataset

summary(iris$Sepal.Length)  # computing the summery of each features available in dataset
summary(iris$Sepal.Width)
summary(iris$Petal.Length)
summary(iris$Petal.Width)
summary(iris$Species)


hist(iris$Sepal.Length) # creating a histogram for each of the attributes
hist(iris$Sepal.Width) 
hist(iris$Petal.Length) 
hist(iris$Petal.Width)

plot(iris$Species, iris$Sepal.Length, col = "#bbccdd", xlab = "Species", ylab = "Sepal Length") #creating a box plot for each of the attributes
plot(iris$Species, iris$Sepal.Width, col = "purple", xlab = "Species", ylab = "Sepal Width")
plot(iris$Species, iris$Petal.Length, col = "pink", xlab = "Species", ylab = "Petal Length")
plot(iris$Species, iris$Petal.Width, col = "blue", xlab = "Species", ylab = "Petal Width")

dev.off() #clearing all plots
