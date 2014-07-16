#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	
}

//--------------------------------------------------------------
void ofApp::update(){

	
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(col);
	ofRect(pos, 100,100);
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
	pos.set(x, y);
	bDragged = true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	clickTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (clickTime > ofGetElapsedTimeMillis()-200){
		doClick(x,y,button);
	}
}
//--------------------------------------------------------------
void ofApp::doClick(int x, int y, int button){
		col.set(ofRandom(255), ofRandom(255), ofRandom(255));
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