import math
import cv2
from itertools import count
from scipy import fftpack
import numpy as np
from matplotlib import pyplot as plt
d=0
for love in range(0,9800) :
	aa = ("ACCEDE%05i.mp4" % love)
	cap = cv2.VideoCapture(aa)
	ctr=0
	troll=0
	f=cap.get(cv2.cv.CV_CAP_PROP_FRAME_COUNT)/25
	g=math.floor(f)
	while not cap.isOpened():
	    cap = cv2.VideoCapture(aa)
	    cv2.waitKey(1000)
	    print "Wait for the header"

	pos_frame = cap.get(cv2.cv.CV_CAP_PROP_POS_FRAMES)
	while True:
	    flag, img = cap.read()
            ctr=ctr+1
	    if flag:
		small = cv2.resize(img, (0,0), fx=1, fy=1) 
		if ctr==g :
			cv2.imshow('video', small)
			cv2.imwrite("ACCEDE%05i.jpg" % d,small)
			d=d+1
			ctr=0
			troll=troll+1
		#ctr=ctr+1
		pos_frame = cap.get(cv2.cv.CV_CAP_PROP_POS_FRAMES)
		#print str(pos_frame)+" frames"
	    else:
		cap.set(cv2.cv.CV_CAP_PROP_POS_FRAMES, pos_frame-1)
		print "frame is not ready"
		cv2.waitKey(1000)
	    if cv2.waitKey(10) == 27:
		break
	    if cap.get(cv2.cv.CV_CAP_PROP_POS_FRAMES) == cap.get(cv2.cv.CV_CAP_PROP_FRAME_COUNT):
		break
	    if troll == 25:
		break
	print d
print d
