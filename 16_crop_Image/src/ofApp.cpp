#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	//////////////////////////////////////////////
	// interface
	w = 160;
	h = 120;
	W = 320;
	H = 240;
	WBig = 640;
	HBig = 480;
	border= 50;


	//////////////////////////////////////////////
	//	kinect
	videoCam.initGrabber(WBig, HBig);
	colorImg.allocate(videoCam.width, videoCam.height);
	grayImage.allocate(videoCam.width, videoCam.height);
	grayThreshNear.allocate(videoCam.width, videoCam.height);
	grayThreshFar.allocate(videoCam.width, videoCam.height);

	
	//////////////////////////////////////////////
	//	Parameters
	gui.setup("panel"); // most of the time you don't need a name but don't forget to call setup
	gui.setPosition(border, 380);
	gui.setSize(W+w, 20);
	gui.add(nearThreshold.set(	"nearThreshold",	250, 0, 255 ));
	gui.add(farThreshold.set(	"farThreshold",		200, 0, 255 ));
	gui.add(cropX.set(	"crop X",	45,	 0, WBig ));
	gui.add(cropY.set(	"crop Y",	45,	 0, HBig ));
	gui.add(cropW.set(	"crop W",	45,	 0, WBig ));
	gui.add(cropH.set(	"crop H",	45,	 0, HBig ));
	
	gui.loadFromFile("settings.xml");
	
}

void ofApp::resizeImages(){

	colorImg.resize				(cropW, cropH);
	grayImage.resize			(cropW, cropH);
	grayThreshNear.resize		(cropW, cropH);
	grayThreshFar.resize		(cropW, cropH);

	lcW=cropW;
	lcH=cropH;
}

//--------------------------------------------------------------
void ofApp::update(){

	
	//////////////////////////////////////////////
	// receive video
    bool bNewFrame = false;
	videoCam.update();
	bNewFrame = videoCam.isFrameNew();
	
	if (bNewFrame){
				
		//////////////////////////////////////////////
		// Grab Camera
//		grayImage.setFromPixels(videoCam.getDepthPixels(), videoCam.width, videoCam.height);
		ofImg.setFromPixels(videoCam.getPixels(), videoCam.getWidth(), videoCam.getHeight(), OF_IMAGE_COLOR);

		//////////////////////////////////////////////
		// Crop
		if (lcW!=cropW || lcH!=cropH){
			resizeImages();
		}
		ofImg.crop(cropX, cropY, cropW ,cropH);

		//////////////////////////////////////////////
		// to grayscale
		colorImg.setFromPixels(ofImg);
		grayImage.setFromColorImage(colorImg);
		
		// we do two thresholds - one for the far plane and one for the near plane
		// we then do a cvAnd to get the pixels which are a union of the two thresholds
		grayThreshNear = grayImage;
		grayThreshFar = grayImage;
		grayThreshNear.threshold(nearThreshold, true);
		grayThreshFar.threshold(farThreshold);
		cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
		
		// update the cv images
		grayImage.flagImageChanged();
		
		// find contours
		runningBlobs = contourFinder.findContours(grayImage, 10, (videoCam.width*videoCam.height)/2, MAX_NUM_CONTOURS_TO_FIND, false);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(100, 50);
	
	videoCam.draw		(border, border, WBig/2, HBig/2);
	colorImg.draw		(border+W+1, border, w, h);
	grayImage.draw		(border+W+1, border+h+1, w, h);
	contourFinder.draw	(border+W+1, border+h+1, w, h);

	//crop
	ofPushStyle();
	ofNoFill();
	ofSetColor(ofColor::yellow);
	ofRect(border+cropX/2, border+cropY/2, cropW/2, cropH/2);
	ofPopStyle();

	// GUI
	gui.draw();

	// draw instructions
	ofSetColor(255, 255, 255);
	stringstream reportStream;
	reportStream << "press h to hide/show image previews" << endl
	<< "press k to stop/start Kinect, current status: " << videoCam.isInitialized() << endl
	<< "num blobs found " << contourFinder.nBlobs << endl
	<< "press ESC to close" << endl
	<< "fps: " << ofGetFrameRate() << endl;
	ofDrawBitmapString(reportStream.str(), border, border+H+20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
