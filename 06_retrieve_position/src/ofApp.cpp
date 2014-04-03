#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    isDragged=false;
    image.loadImage("xenakis.jpg");
    step = 0;
    numSteps = 3;
    originalPoint.set(164,124);
    mat.makeIdentityMatrix();
	pare.setPosition(0, 0, 0);
	node.setParent(pare);
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(128);
	
    mat.makeIdentityMatrix();
    node.getParent()->resetTransform();
	node.setPosition(originalPoint);
    vec=originalPoint;
	
	
    if(step==0)
    {
		// origin
		ofSetColor(255);
		image.draw(0,0);
		ofSetColor(255,0,0);
		ofCircle(originalPoint,5);
		
		node.getParent()->setScale(1);
		transformedPoint = originalPoint * mat;

		ofSetColor(255);
        ofDrawBitmapString(ofToString(step) +" :: point draw at " +ofToString(originalPoint),0,20);
    }
    else if(step == 1)
    {
        ofPushMatrix();
			ofScale(2,2);
			// apply transformation to mattrix and ofNode and vector
			mat.scale(2,2,1);
			node.getParent()->setScale(2,2,1);
			vec*=2;

		// origin
		ofSetColor(255);
		image.draw(0,0);
		ofSetColor(255,0,0);
		ofCircle(originalPoint,5);

		ofPopMatrix();
		
        transformedPoint = originalPoint * mat;
        
		ofSetColor(255);
        ofDrawBitmapString(ofToString(step) +" :: point*mat (scale 2,2) : " +ofToString(transformedPoint),0,20);

    }
    else if(step == 2)
    {
		ofVec3f rAxis=ofVec3f(0,0,1);
        ofPushMatrix();
			ofScale(2,2);
			ofRotate(10,0,0,1);
			// apply transformation to mattrix and ofNode and vector
			mat.scale(2,2,2);
			mat.rotate(10, rAxis.x, rAxis.y, rAxis.z);
			node.getParent()->setScale(2,2,1);
			node.getParent()->setOrientation(rAxis*10);
			vec*=2; // i think it would be really nice to do vec.scale(2);
			vec.rotate(10, rAxis);

		// origin
		ofSetColor(255);
		image.draw(0,0);
		ofSetColor(255,0,0);
		ofCircle(originalPoint,5);

		ofPopMatrix();
        
        transformedPoint = originalPoint * mat;

		ofSetColor(255);
        ofDrawBitmapString(ofToString(step) +" :: point*mat (scale 2,2) + (rot Z 10) : " +ofToString(transformedPoint),0,20);
    }

	
	// draw mat
	ofSetColor(0,255,0);
	ofCircle(transformedPoint,15);
	
	// draw node
	ofSetColor(0,0,255);
	ofCircle(node.getGlobalPosition(),20);
	
	// draw vec
	ofSetColor(0,255,255);
	ofCircle(vec,25);

    if(isDragged)
    {
        ofSetColor(255);
        ofDrawBitmapString(ofToString(ofGetMouseX()) + " , " +ofToString(ofGetMouseY()),ofGetMouseX()+20,ofGetMouseY()+20);
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key==OF_KEY_LEFT)
    {
        step = step-1;
        if(step<0) step = numSteps-1;
    }
    else if(key==OF_KEY_RIGHT)
    {
        step = (step+1)%numSteps;
    }
    
    cout << "step : " <<step <<endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    isDragged=true;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    cout << x << " , " << y << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    isDragged=false;
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