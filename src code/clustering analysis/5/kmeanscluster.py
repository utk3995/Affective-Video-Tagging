from sklearn.cluster import KMeans
from sklearn import preprocessing
import numpy as np 
import re


fread = open("AV_values_liris.txt","r")
feature_list = np.array([[]])
target = open("cluster.txt","w")

polyShape = []
with open('AV_values_liris.txt') as f:
  for line in f:
    line = line.split() # to deal with blank 
    if line:            # lines (ie skip them)
        line = [float(i) for i in line]        
        polyShape.append(line)
        
kmeans = KMeans(n_clusters = 5).fit(polyShape)


for item in kmeans.labels_:
	target.write("%s\n" % (item))




