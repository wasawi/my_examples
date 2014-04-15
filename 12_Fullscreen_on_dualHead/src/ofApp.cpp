#ifndef GLFWWINDOW
#define GLFWWINDOW // comment this to turn off GLFW
#endif

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

#if !defined GLFWWINDOW
	ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight()*2);
#elif defined GLFWWINDOW
	ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight()*2);
#endif
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(100, 50);
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
