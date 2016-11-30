import pandas as pd
from random import randint
import pylab as pl
from sklearn.neighbors import KNeighborsClassifier
import numpy as np
import os
#input feature 2 d array
#input tag
#input test
#input ans
with open("featurefile.txt") as textFile:
    features = [line.split() for line in textFile]
with open("tagfile.txt") as textFile:
    tagg = [line.split() for line in textFile]
tagi=np.array(tagg)
tag=np.ravel(tagi)
with open("testfile.txt") as textFile:
    test = [line.split() for line in textFile]
#with open("ansfile.txt") as textFile:
#    ans = [line.split() for line in textFile]
clf = KNeighborsClassifier(n_neighbors=2,weights='distance')
clf.fit(features, tag)
preds = clf.predict(test)
#b=[i for i, j in zip(preds, ans) if i == j]
#print b
#print len(b)
print preds
outfile = open('outputfile.txt', 'w')
for i in preds:
  outfile.write(str(i))
  outfile.write('\n')
outfile.close()
os.system("./accuracy_check")
