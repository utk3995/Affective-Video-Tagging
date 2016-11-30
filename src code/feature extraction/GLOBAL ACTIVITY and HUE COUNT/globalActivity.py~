#!/usr/bin/env python

import numpy as np
import cv2
import math

if __name__ == '__main__':
	target = open('global.txt', 'w')
	for ctr in range (0,9800) :
	    aa = ("ACCEDE%05i.mp4" % ctr)
	    print aa
	    cam = cv2.VideoCapture(aa)
	    ret, prev = cam.read()
	    prevgray = cv2.cvtColor(prev, cv2.COLOR_BGR2GRAY)
	    show_hsv = False
	    show_glitch = False
	    cur_glitch = prev.copy()
	    frames=0
	    globalActivity=0
	    step=16
	    flag=0
	    while True:
			ret, img = cam.read()
			frames=frames+1
			if (type(img) == type(None)):
				break		
			gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)			
			flow = cv2.calcOpticalFlowFarneback(prevgray, gray, 0.5, 3, 15, 3, 5, 1.2, 0)
			prevgray = gray
			h, w = gray.shape[:2]
    			y, x = np.mgrid[step/2:h:step, step/2:w:step].reshape(2,-1)
    			fx, fy = flow[y,x].T
			for dx,dy in zip(fx,fy):
				globalActivity=globalActivity+math.sqrt(dx*dx+dy*dy)   			
			ch = 0xFF & cv2.waitKey(5)
			if ch == 27:
			    break
			
	    
	    cam.release()
	    cv2.destroyAllWindows()
     	    res=globalActivity/frames
	    res=res/10
     	    round(res,3)
	    target.write((str)(res))
	    target.write('\n')
