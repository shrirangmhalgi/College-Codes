import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from pandas.plotting import scatter_matrix

names = ['sepal-length', 'sepal-width', 'petal-length', 'petal-width', 'class']
dataset = pd.read_csv("iris.csv", names=names)
print(dataset.shape)                    # Shape
# print(dataset.head(5))                # Peek data
print(dataset.describe())               # Descriptions
print(dataset.groupby('class').size())  # Class distribution

# Box and whisker plots
dataset.plot(kind='box', subplots=True, layout=(2, 2), sharex=False, sharey=False)
plt.show()

# Histogram
dataset.hist()
plt.show()

# Scatter plot matrix
scatter_matrix(dataset)
plt.show()
