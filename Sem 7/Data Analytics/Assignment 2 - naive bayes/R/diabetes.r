# Download  Pima Indians Diabetes dataset. 
# Use Naive Bayes Algorithm for classification 
# Load the data from CSV file and split it into training and test datasets.
# summarize the properties in the training dataset so that we can calculate probabilities and make predictions.
# Classify samples from a test dataset and a summarized training dataset. 

library(e1071) #library required for the naiveBayes function
library(caTools) #library required for the sample.split function
library(caret)

setwd("C:\\Users\\DELL\\Desktop\\Sem 7 submissions\\Lab Practise 1\\Data Analytics\\Assignment 2 - naive bayes\\R")
diabetes <- read.csv("PimaIndiansDiabetes.csv")
head(diabetes)

diabetes_split <- sample.split(diabetes, SplitRatio = 0.9) #splitting it into training and test data in ratio 0.9
diabetes_train <- subset(diabetes, diabetes_split == TRUE)
diabetes_test <- subset(diabetes, diabetes_split == FALSE)

nb_default <- naiveBayes(Class~.,data = diabetes_train) #training the model with training data to predict the class lable taking all other attributes into consideration
nb_predict <- predict(nb_default, newdata = diabetes_test, "raw") #applying the trained model on test data

highest_prob <- as.factor(colnames(nb_predict)[apply(nb_predict, 1, which.max)]) #applying appropriate label based on predicted values
table(highest_prob, diabetes_test[,9]) #displaying table of predicted outcome vs actual outcome
table(highest_prob)
table(diabetes_test[,9])

png(file = "pie90-10.png")
labs <- c("No diabetes","Diabetes")
pie(table(highest_prob),labels = labs)
dev.off()
