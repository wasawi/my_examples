#include "ofApp.h"
#include "teapot.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(60);
	ofDisableSetupScreen();

	fbo.setup(300, 0, width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);
	ofSetBackgroundColor(100);
	ofEnableDepthTest();

	// get the total elapsed time
	float playTime = ofGetElapsedTimef();

	// compute rotation angle
	const float ANGLE_SPEED = 20;   // degree/s
	float angle = ANGLE_SPEED * playTime;
	float scale = 100;
	float plane = 1000;

	// set coordinates to top left
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeight, 0, -plane, plane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

 	// draw a rotating teapot at the origin
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glScalef(scale, scale, scale);
 	glRotatef(angle*0.5f, 1, 0, 0);
 	glRotatef(angle, 0, 1, 0);
 	glRotatef(angle*0.7f, 0, 0, 1);
 	drawTeapot();
 	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glPushMatrix();

	//-----------------------------------------
	fbo.begin();
	//-----------------------------------------

	// draw a rotating teapot at the origin
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glScalef(scale, scale, scale);
	glRotatef(angle*0.5f, 1, 0, 0);
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle*0.7f, 0, 0, 1);
	drawTeapot();
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//-----------------------------------------
	fbo.end();
	//-----------------------------------------

	glPopMatrix();

	// set coordinates to top left
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeight, 0, -plane, plane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//-----------------------------------------
	fbo.draw();
	//-----------------------------------------

}

void ofApp::exit()
{
	fbo.destroy();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // update mouse x and y percent when the mouse moves
    mouseXPercent = float(x) / ofGetWidth();
    mouseYPercent = float(y) / ofGetHeight();
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
