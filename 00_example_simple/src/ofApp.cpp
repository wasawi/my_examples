#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();
	sliderInt = 100;
	color = ofColor::blue;
	cursor = ofPoint(ofGetWindowWidth() / 2 - sliderInt / 2, ofGetWindowHeight() / 2 - sliderInt / 2);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::black);
	ofDrawRectangle(ofGetWindowWidth() / 2 - sliderInt / 2, ofGetWindowHeight() / 2 - sliderInt / 2, sliderInt, sliderInt);
	ofSetColor(ofColor::yellow);
	ofDrawCircle(cursor.x, cursor.y, sliderInt / 2);
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
	cursor = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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