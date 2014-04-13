#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0);
	
    fbo.allocate(ofGetWidth()/2, ofGetHeight(), GL_RGBA);
    fbo.begin();
	ofBackground(0);
//	ofSetColor(0, 0, 0, 255);
//	ofFill();
//	ofRect(0, 0, ofGetScreenWidth()/2, ofGetScreenHeight());
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
//	ofDisableAlphaBlending();
//	ofEnableBlendMode(OF_BLENDMODE_DISABLED);
	//    ofEnableAlphaBlending();
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
//		ofEnableBlendMode(OF_BLENDMODE_SCREEN);
//	ofSetColor(0, 0, 0, 2);
    // Draw directly to screen
    drawCircle();
//	ofDisableAlphaBlending();
//	ofEnableBlendMode(OF_BLENDMODE_DISABLED);
	
    // Draw to fbo
    fbo.begin();
//	ofSetColor(0, 0, 0, 2);
//    ofEnableAlphaBlending();
//    ofDisableBlendMode();
	//This is what is normally called with ofEnableAlphaBlending
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//if you have changed your blend equation, uncomment to return to default
	//glBlendEquation(GL_FUNC_ADD);
//	drawCircleFBO();
	drawCircle();
    fbo.end();
	
//	ofEnableAlphaBlending();
//	ofDisableAlphaBlending();

//	glEnable(GL_BLEND);
//	ofEnableBlendMode(OF_BLENDMODE_ADD);
//	ofEnableBlendMode(OF_BLENDMODE_DISABLED);
//	ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
//	ofEnableBlendMode(OF_BLENDMODE_SCREEN);
//	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);

    fbo.draw(ofGetWidth()/2, 0);
}
//--------------------------------------------------------------
void ofApp::drawCircle() {
	ofPushStyle();
	
	ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, 2);
    ofFill();
    ofRect(0, 0, ofGetScreenWidth()/2, ofGetScreenHeight());
	
	ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(50, 50, 255, 255);
    ofCircle(ofRandomWidth()/2, ofRandomHeight(), 30);

	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::drawCircleFBO() {

//	ofPushStyle();
//	glEnable(GL_BLEND);
//	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);

	

//	ofEnableAlphaBlending();
	ofDisableAlphaBlending();
	
//	ofEnableBlendMode(OF_BLENDMODE_DISABLED);
//	ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
//	ofEnableBlendMode(OF_BLENDMODE_SCREEN);
//	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);

//	ofClear(255, 255, 255, 2);
//	ofClear(255, 255, 255, 223);
//	ofClear(0, 0, 0, 223);
//	ofClear(0, 0, 0, 2);
	ofSetColor(0, 0, 0, 0);
	ofFill();
	ofRect(0, 0, ofGetScreenWidth()/2, ofGetScreenHeight());
	
//	ofEnableAlphaBlending();
//	ofDisableAlphaBlending();

//	glEnable(GL_BLEND);
//	ofEnableBlendMode(OF_BLENDMODE_DISABLED);
//	ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
//	ofEnableBlendMode(OF_BLENDMODE_SCREEN);
//	ofEnableBlendMode(OF_BLENDMODE_ADD);

//	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_COLOR);
//	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);
//	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);

	ofSetColor(50, 50, 255, 255);
	ofCircle(ofRandomWidth()/2, ofRandomHeight(), 30);
//	ofPopStyle();
}

/*
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofBackground(0);
	
    fbo.allocate(ofGetWidth()/2, ofGetHeight(), GL_RGBA32F);
    fbo.begin();
	ofBackground(0);
    fbo.end();
}

void ofApp::draw(){
    // Draw directly to screen
    drawCircle();
	
    // Draw to fbo
    fbo.begin();
	drawCircle();
    fbo.end();
    ofDisableBlendMode();
    fbo.draw(ofGetWidth()/2, 0);
}

void ofApp::drawCircle() {
    ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, 2);
    ofFill();
    ofRect(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
    ofSetColor(50, 50, 255, 255);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofCircle(ofRandomWidth()/2, ofRandomHeight(), 50);
}
*/
 
//--------------------------------------------------------------
void ofApp::update(){
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
