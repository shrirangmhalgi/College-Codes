import pandas as pd
import numpy as np
import copy
import matplotlib.pyplot as plt

df = pd.read_csv("data.csv") # reading the dataset

np.random.seed(200) # setting a random seed from 0 to 200
k = 2 # setting the K value

# creating the centroid dictionary
centroids = {
    0:[0.1,0.6],
    1:[0.3,0.2]
}

def assignment(df, centroids):
    # calculating the centroid distance
    for i in centroids.keys():
        # sqrt((x1 - x2)^2 - (y1 - y2)^2)
        df['distance_from_{}'.format(i)] = (
            np.sqrt(
                (df['x'] - centroids[i][0]) ** 2
                + (df['y'] - centroids[i][1]) ** 2
            )
        )
    centroid_distance_cols = ['distance_from_{}'.format(i) for i in centroids.keys()] # creating the centroid columns
    df['closest'] = df.loc[:, centroid_distance_cols].idxmin(axis=1) # finding the closest neighbors
    df['closest'] = df['closest'].map(lambda x: int(x.lstrip('distance_from_'))) # mapping the df
    return df

print("dataframe is : ") # printing the data frame
print(df) # printing the data frame

# finding the mean of centroids
def update(k):
    for i in centroids.keys():
        centroids[i][0] = np.mean(df[df['closest'] == i]['x'])
        centroids[i][1] = np.mean(df[df['closest'] == i]['y'])
    return k

df = assignment(df, centroids)
centroids = update(centroids)

# finding the closest centroid
while True:
    closest_centroids = df['closest'].copy(deep=True)
    df = assignment(df, centroids)
    centroids = update(centroids)
    if closest_centroids.equals(df['closest']):
        break

print(df['closest'][5])
print(centroids)

plt.scatter(df['x'] , df['y'] , c=df['closest']) # plotting the plot
plt.show() # displaying the plot

#using sklearn
from sklearn.cluster import KMeans

df = pd.read_csv("data.csv") # importing the data

init_cluster = np.ndarray( shape=(2,2), dtype=float , buffer=np.array( [[0.1,0.6], [0.3,0.2]] ) ) # creating cluster

kmeans = KMeans(init=init_cluster, n_clusters=2) # creating object of KMeans
kmeans.fit(df) # fitting the data
labels = kmeans.predict(df) # predicting the results
centroids = kmeans.cluster_centers_ # storing the centroids

plt.scatter(df['x'] , df['y'] , c=kmeans.labels_) # plotting the plot
plt.show() # displaying the plot

print(labels) # printing the labels
print(kmeans.cluster_centers_) # printing the centroids