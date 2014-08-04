#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofLogNotice("ofGetUserName()")<<ofGetUserName();
	ofLogNotice("ofGetAppName()")<<ofGetAppName();
	ofLogNotice("ofGetAppPath()")<<ofGetAppPath();
	ofLogNotice("ofGetCurrentPath()")<<ofGetCurrentPath();
	
	
	
//--------------------------------------------------------------
	// draw something
	w=h=255;
	img.allocate(w, h, OF_IMAGE_COLOR);
	img.setColor(ofColor::white);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			ofColor color= ofColor(255-i%w,j%h,255);
			img.setColor(i % w, j % h, color);
		}
	}
	img.update();

}

//--------------------------------------------------------------
void ofApp::update(){

	if (counter == 300){
		
		// ATTENTION
		// THIS CAN DESTROY ALL YOUR WORK!!
		// make sure you understand what you are doing
		// keep inside the counter for security

		ofRestart();
		//	ofCrash();
		// ofKillApp("iTunes");
	}
	counter++;

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawBitmapString(ofToString(counter), 10, 20);
	img.draw(100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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