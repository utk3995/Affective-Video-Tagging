import cv2
from scipy import fftpack
import numpy as np
from matplotlib import pyplot as plt
from itertools import count

target = open('color_light_data.txt', 'w')

for ctr in range (0,9800) : 
	aa = ("ACCEDE%05i.mp4" % ctr)
	print aa
	cap = cv2.VideoCapture(aa)
	while not cap.isOpened():
	    cap = cv2.VideoCapture(aa)
	    cv2.waitKey(1000)
	    print "Wait for the header"

	pos_frame = cap.get(cv2.cv.CV_CAP_PROP_POS_FRAMES)

	colorsum1 = 0
	colorpixel1 = 0

	lightsum2 = 0
	lightpixel2 = 0

	while True:
	    flag, imga = cap.read()
	    if flag:
		# The frame is ready and already captured   BGR

		# edit here

		img = cv2.resize(imga, (0,0), fx=0.5, fy=0.5) 
		img2 = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
		cv2.imshow('video', img)

		i = 0
		sum = 0
		w = len(img)
		h = len(img[0])
		rglist = [None] * w * h
		yblist = [None] * w * h	
		for x in range(0,w):
			for y in range(0,h):
				rglist[i] = ( ((img.item(x,y,2)) - (img.item(x,y,1)) ) );  #  R - G
				yblist[i] = ( (0.5 * ((img.item(x,y,2)) + (img.item(x,y,1))) - (img.item(x,y,0))) ); #  1/2(R + G) - B
				sum = sum + img2.item(x,y)
				i = i+1
		stdRG = np.std(rglist)
		meanRG = np.mean(rglist)

		stdYB = np.std(yblist)
		meanYB = np.mean(yblist)

		stdRGYB = ((stdRG)**2 + (stdYB)**2)**0.5
	    	meanRGYB = ((meanRG)**2 + (meanYB)**2)**0.5

		C = stdRGYB + 0.3*meanRGYB

		colorsum1 = colorsum1 + C
		colorpixel1 = colorpixel1 + 1

		
		sum = sum / (w*h)
		lightsum2 = lightsum2 + sum
		lightpixel2 = lightpixel2 + 1


		# print C 


		# edit over

		pos_frame = cap.get(cv2.cv.CV_CAP_PROP_POS_FRAMES)

		# print str(pos_frame)+" frames"
	    else:
		# The next frame is not ready, so we try to read it again
		cap.set(cv2.cv.CV_CAP_PROP_POS_FRAMES, pos_frame-1)
		print "frame is not ready"
		# It is better to wait for a while for the next frame to be ready
		# cv2.waitKey(1000)

	    if cv2.waitKey(10) == 27:
		break
	    if cap.get(cv2.cv.CV_CAP_PROP_POS_FRAMES) == cap.get(cv2.cv.CV_CAP_PROP_FRAME_COUNT):
		# If the number of captured frames is equal to the total number of frames,
		# we stop
		break
	
	target.write(str(colorsum1/colorpixel1))
	target.write('\t')
	target.write(str(lightsum2/lightpixel2))
	target.write('\n')
