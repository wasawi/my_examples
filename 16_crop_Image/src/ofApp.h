#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"

// COUNTOUR FINDER
#define		MAX_NUM_CONTOURS_TO_FIND	1


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
	
	
	ofVideoGrabber				videoCam;
	ofImage						ofImg;
	ofxCvColorImage				colorImg;
	ofxCvGrayscaleImage			grayImage;
	ofxCvGrayscaleImage			grayThreshNear; // the near thresholded image
	ofxCvGrayscaleImage			grayThreshFar; // the far thresholded image
	ofxCvContourFinder			contourFinder;
	
	//crop
	ofImage cropOfImage;
	
	// Panel
	ofxPanel gui;
	int w, h, W, H, WBig, HBig,  border;
	ofParameter<float>		nearThreshold,
							farThreshold;
	
	ofParameter<int>		cropX,
							cropY,
							cropW,
							cropH;
	int lcX,lcY,lcW,lcH;
	
	// output
	int runningBlobs;
	
	void resizeImages();
};
