import cv2
import os
import numpy as np
import time
from matplotlib import pyplot as plt
foo = open('features.txt','w')
foo.truncate()
for filectr in range (0,9800) :
	target = open('datafile.txt', 'w')
	target.truncate()
	aa = ("ACCEDE%05i.jpg" % filectr)
	print aa
	#start_time = time.time()
	#img = cv2.imread('www.png')
	#img = cv2.cvtColor( img, cv2.COLOR_RGB2GRAY )
	#row = len(img)
	#col = len(img[0])
	'''
	    INTER_NEAREST - a nearest-neighbor interpolation
	    INTER_LINEAR - a bilinear interpolation (used by default)
	    INTER_AREA - resampling using pixel area relation. It may be a preferred method for image decimation, 
            as it gives moire-free results. 
	    But when the image is zoomed, it is similar to the INTER_NEAREST method.
	    INTER_CUBIC - a bicubic interpolation over 4x4 pixel neighborhood
	    INTER_LANCZOS4 - a Lanczos interpolation over 8x8 pixel neighborhood
	'''

	for k in range ((int)(1),(int)(6)):
		img = cv2.imread(aa)
		img = cv2.cvtColor( img, cv2.COLOR_RGB2GRAY )
		roww=len(img)
		coll=len(img[0])
		facx=100.00/roww
		facy=100.00/coll
		img = cv2.resize(img,None,fx=facx, fy=facy, interpolation = cv2.INTER_LANCZOS4) 
		#cv2.imwrite( "lol.jpg",img)
		row = len(img)
		col = len(img[0])
		kernel = np.ones((k,k),np.float32)/(k*k)
		dst = cv2.filter2D(img,-1,kernel)
		target.write(str(k))
		target.write('\n')
		target.write(str(row))
		target.write('\n')
		target.write(str(col))
		target.write('\n')
		#print k
		#print col,row
		for i in range(0,row):
			for j in range(0,col):
				#dst[i][j]=dst[i][j]
				#target.write(str(dst[i][j]))
				target.write(str(dst.item(i,j)))
				target.write(' ')
			target.write('\n')

	target.close()
	os.system("./final1")
#os.system("./dof")
'''
print np.matrix(dst)
#print dst.shape
#print img.shape
#n=int(input())
#print "now"
dx= np.array([1,-1])
dy = np.array([[1],[-1]])
Ma = len(dst)
Na = len(dst[0])
Mb = len(dy)
Nb = len(dy[0])

#print Mb
#print Nb
conv1 = [[0 for x in range(Na+Nb)] for x in range(Ma+Mb)] 
#n=max(Na+Nb,Ma+Mb)
#conv1 = [[0]*n for _ in range(n)]
print "now"
for m in range(0,Ma):
	for n in range(0,Na):
		for i in range(m,Mb+m):
			for j in range(n,Nb+n):
				conv1[i][j] = conv1[i][j]+ dst[m][n] * dy[i-m][j-n]
print np.matrix(conv1)
for i in range(Ma+Mb):
	for j in range(Na+Nb):
		conv1[i][j]=abs(conv1[i][j])
Mb = 1
Nb = 2
conv2 = [[0 for x in range(Na+Nb)] for x in range(Ma+Mb)] 
for m in range(0,Ma):
	for n in range(0,Na):
		for i in range(m,Mb+m):
			for j in range(n,Nb+n):
				conv2[i][j] = conv2[i][j]+ dst[m][n] * dx[j-n]


conv1=np.array(conv1)
conv2=np.array(conv2)
cv2.imwrite( "ver1.jpg", conv1 )
cv2.imwrite( "ver2.jpg", conv2 )
plt.subplot(121),plt.imshow(conv1),plt.title('vertical')
plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(conv2),plt.title('horizantal')
plt.xticks([]), plt.yticks([])
plt.show()'''
print "finally"
#print("--- %s seconds ---" % (time.time() - start_time))