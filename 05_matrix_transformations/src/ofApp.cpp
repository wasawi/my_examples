#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(100, 50);
	
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPoint myPoint(50, 50);
    ofSetColor(ofColor::green);
    ofCircle(myPoint, 20);
	
    //=================================== ok
    ofPushMatrix();
		ofMatrix4x4 translation = ofMatrix4x4::newTranslationMatrix(ofVec3f(ofGetWidth()/2,ofGetHeight()/2,0));
		ofMatrix4x4 rotation = ofMatrix4x4::newRotationMatrix(45, 0, 0, 1);
		ofMultMatrix(translation);
		ofMultMatrix(rotation);
		ofSetColor(ofColor::red);
		ofCircle(myPoint, 20);
    ofPopMatrix();

    //================================== wrong
	// will first translate your point and then rotate the coordinate system 45 degrees
    ofPushMatrix();
		ofVec3f aPoint;
		aPoint = myPoint * translation;
		aPoint = aPoint * rotation;
		ofSetColor(ofColor::maroon);
		ofCircle(aPoint, 15);
    ofPopMatrix();
	
    //================================== ok
	// will first rotate your point 45 degrees, then translate
    ofPushMatrix();
		ofVec3f absolutePoint;
		absolutePoint = myPoint * rotation;
		absolutePoint = absolutePoint * translation;
		ofSetColor(ofColor::blue);
		ofCircle(absolutePoint, 15);
    ofPopMatrix();

    //================================== wrong
	// will first translate your point and then rotate the coordinate system 45 degrees
	// notice that the order of transformations is wrong. matrices need reversed order
    ofPushMatrix();
		ofMatrix4x4 ofm;
		ofm.translate(ofGetWidth()/2,ofGetHeight()/2,0);
		ofm.rotate(45, 0, 0, 1);
		ofVec3f ofv(0,0,0);
		ofv = myPoint * ofm;
		ofSetColor(ofColor::yellow);
		ofCircle(ofv, 5);
    ofPopMatrix();
	
    //================================== ok
	// will first translate your point and then rotate the coordinate system 45 degrees
	// reversing the order of transformation will fix it.
    ofPushMatrix();
		ofMatrix4x4 ofmm;
		ofmm.rotate(45, 0, 0, 1);
		ofmm.translate(ofGetWidth()/2,ofGetHeight()/2,0);
		ofVec3f ofvv(0,0,0);
		ofvv = myPoint * ofmm;
		ofSetColor(ofColor::cyan);
		ofCircle(ofvv, 10);
    ofPopMatrix();
    //================================== ok
	// will first translate your point and then rotate the coordinate system 45 degrees
	// glTransforms work the other way around.. no need to reverse
    ofPushMatrix();
		ofMatrix4x4 glm;
		glm.glTranslate(ofGetWidth()/2,ofGetHeight()/2,0);
		glm.glRotate(45, 0, 0, 1);
		ofVec3f glv(0,0,0);
		glv = myPoint * glm;
		ofSetColor(ofColor::white);
		ofCircle(glv, 5);
    ofPopMatrix();
	
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