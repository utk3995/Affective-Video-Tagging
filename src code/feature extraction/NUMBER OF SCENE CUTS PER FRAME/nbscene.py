import re
import scenedetect
import cv2

l_range = 0
r_range = 9800

#opening file for writing the scene cut per frame value of the videos..
fp = open("nbscene.txt","w")

#reading for 9800 video files .....
for videocount in range(l_range,r_range):
	videoname = ("ACCEDE%05i.mp4" % videocount)

	#this list contains all the frame index of the scene cuts for the video....
	#declaring the path for the current video....
	scene_list = [] 
	path = videoname

	#defining the detector list for the detection...
	#using the content based scene cut detector with the value for threshold be 30
	detector_list = [scenedetect.detectors.ContentDetector(threshold = 30)]

	#calling the detect_scene_file with the arguments path for the video, scene_list , and finally
	#the detector list which will be used for the detection of the frames...
	scenedetect.detect_scenes_file(path, scene_list, detector_list)
	scene_cuts = len(scene_list)

	#to count number of frames using the below command....
	cap = cv2.VideoCapture(videoname)
	length = float(cap.get(cv2.CAP_PROP_FRAME_COUNT))
	
	#writing the value in the file ....
	fp.write("%s - %lf"%(videoname,scene_cuts/length))
	fp.write("\n")

fp.close()