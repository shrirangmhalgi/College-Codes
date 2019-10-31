library(rpart) #library required for decision tree
library(caTools)
library(e1071)
library(rpart.plot) #library required for plotting the decision tree
library(RColorBrewer)

#install.packages("rattle", dependencies = TRUE, repos='http://cran.rstudio.com/')
setwd("C:\\Users\\DELL\\Desktop\\Sem 7 submissions\\Lab Practise 1\\Data Analytics\\Assignment 4 - decision tree\\R")
data <- read.csv('2010-capitalbikeshare-tripdata.csv')

# To display number of rows and columns in data
dim(data)

set.seed(123)

my_sample <- sample.split(data, SplitRatio = 0.8) #creating a sample

biker_train <- data[my_sample, c(1,4,6,9)] #training data containing the sample and 4 specific columns
biker_test <- data[!my_sample, c(1,4,6,9)]

summary(biker_test)
summary(biker_train)

fit <- rpart(biker_train$Member.type~., data = biker_train, method = "class") #building decision tree model based on training data to predict Member Type on the basis of all other attributes

fit

fancyRpartPlot(fit)

rpart.plot(fit)
rpart.plot(fit,type=4,extra=101)

prediction <- predict(fit,newdata = biker_test[,-4],type = ("class")) #making predicions on test data using the model made
table(biker_test[,4],prediction) #table comparing predicted type with actual type
table(prediction)

png(file="trypie.png")
labs <- c("Member","Casual")
pie(table(prediction),labels = labs)
dev.off()
