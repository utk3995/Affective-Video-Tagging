AFFECTIVE VIDEO ANALYSIS		

###############################################################################################################################################
Prepared by :

Mohd Abdullah 		ism2014004 	ism2014004@iiita.ac.in		8733817563
Swapnaneel Nandy 	iit2014111	iit2014111@iiita.ac.in		8756438637
Utkarsh Srivastava 	iit2014507	iit2014507@iiita.ac.in		9565127792
Shivam Beri		iit2014159	iit2014159@iiita.ac.in		9794129942
Amit Vijay		iit2014110	iit2014110@iiita.ac.in		7054024261


###############################################################################################################################################

Libraries Required : 

1- python-Numpy
2- python-OpenCV
3- python-matplotlib
4- python-sckitlearn-scipy
5- python-itertools
6- pyscenedetect
7- Yaafe

###############################################################################################################################################
Procedures for Feature Extraction :

The programs for feature extraction are present in folder of respective feature names and some sample videos have been supplied for testing in folder named "SAMPLE VIDEOS". The procedure for each feature extraction are as follows:-

1 : DEPTH OF FIELD and COMPOSITIONAL BALANCE-
	-run framefinder.py (it will generate frames for all 9800 videos).
	-run dof_cb.py (it will generate a file feature.txt which will contain 9800 rows, each row will have two values compositional balance 
	and depth of field.

2 : COLORFULNESS and LIGHTING : 
	-run python color_light.py
	-We will get a feature vector file named color_light_data.txt containing feature vector for 9800 videos.
	
3 : GLOBAL ACTIVITY and HUE COUNT :
	-run either "python globalActivity.py" or "python globalActivity.py" on terminal..
	-We will get a feature vector file named either global.txt or hueCount.txt containing feature vector for 9800 videos of respective 		feature.

4 : NUMBER OF SCENE CUTS PER FRAME :
	-install pyscene library present in folder
	-run "python nbscene.py" on terminal.
	-We will get a feature vector file named "nbscene.txt" for feature vector of 9800 videos.

5 : ZCR, SPECTRAL SLOPE and SPECTRAL FLATNESS:
	-install the library (Yaafe) present in folder
	-Convert the video mp4 to audio format (wav) using ffmpeg.
	-run the scpt_zcr,scpt_ss and scpt_sf script. 
	-now compile (using -std=c++11 ) and run parse.cpp to produce features files named zcr.txt, sf.txt and ss.txt which contain respective 		 features for 9800 videos.
6 : LENGTH OF SCENE CUT :
	-install the pyscene library present in folder
	
###############################################################################################################################################

classification based on tagged data :

The codes are present in the folder "classification analysis on tagged data".

Files description :
1- a feature vector file "feature.txt", containing 11 features for 9800 videos.
2- a tagged data file "cluster.txt", which has classes numbered as [1-4].
('1' denotes : HAPPY/EXCITED)
('2' denotes : FURIOUS/ANNOYED/DISGUSTED)
('3' denotes : DISAPPOINTED/DEPRESSED/BORED)
('4' denotes : CALM/SERENE/RELAXED)
3- a file named "knn.py" to run knn
4- a file named "accuarcy_check.cpp" to check accuracy.

Steps :
1- generate an execuatble file of the "accuracy_check.cpp" (it might give segfault initially, just ignore it).
2- run knn.py on terminal
3- check accuracy displayed by the programm knn.py

###############################################################################################################################################

clustering based on AV values (experimentation) :

The codes are present in the folder "clustering analysis". There are folder numbered as [4-8] inside folder "clustering analysis" for analysis of clusters having total clusters as foldername.

Files description for each folder :
1- a feature vector file "feature_vector_our_11.txt", containing 11 features for 9800 videos.
2- a file named "AV_values_liris.txt" which contains arousal valence values on which we cluster.
3- a filenamed "kmeanscluster.py" to run kmeans and generate clustered data in a filenamed "cluster.txt".
4- a program named "format_input.cpp" to generate files used for knn (features divide in 70-30 percent ratio).
5- a file named "knn.py" to run knn
6- a file named "accuarcy_check.cpp" to check accuracy.

Steps :
1- run kmeanscluster.py
2- run format_input.cpp
3- generate an execuatble file of the "accuracy_check.cpp" (it might give segfault initially, just ignore it).
4- run knn.py on terminal
5- check accuracy displayed by the programm knn.py

###############################################################################################################################################
