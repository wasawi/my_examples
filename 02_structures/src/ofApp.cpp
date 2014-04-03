#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	person p1;
	p1.name	= "Tom";
	p1.age	= 34;
	
	person p2;
	p2.name	= "Pablo";
	p2.age	= 29;
	
	cout <<"The age of "<< p1.name <<" is "<< p1.age <<endl;
	cout <<"The age of "<< p2.name <<" is "<< p2.age <<endl;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
