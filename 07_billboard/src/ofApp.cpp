#include "ofApp.h"

// Example by Jordi Puig

//--------------------------------------------------------------
void ofApp::setup(){
	
	// let the axis oclude
	ofEnableDepthTest();
	
	ofSetCircleResolution(60);
	ofSetSphereResolution(5);
	// set attributes to our displayed plane
	plane.setPosition(0 ,0, 0);
	plane.setScale(1,2,1);
	
}

//--------------------------------------------------------------
void ofApp::update(){

	
	// simple billboard
	plane.lookAt(cam.getGlobalPosition(), cam.getUpDir());
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(100, 50);
	
	cam.begin();
	
	//http://forum.openframeworks.cc/t/billboard-using-ofnode/14142
    ofDrawAxis(500);
    ofSeedRandom(0);    // always pick the same random positions
    
    for (int i = 0; i < 10; i++){
        
        ofPoint pos(ofRandom(-200,200), ofRandom(-200,200), ofRandom(-200,200));
        
        ofNode posNode;
        posNode.setGlobalPosition(pos);
        posNode.lookAt(cam.getGlobalPosition(), cam.getUpDir());
//        posNode.lookAt(cam.getPosition()); this will do, but the object will rotate ugly.
        ofQuaternion posQuat = posNode.getGlobalOrientation();
		
        float ang = 0;
        ofPoint vec;
        posQuat.getRotate(ang, vec);
        
        ofPushMatrix();
			ofTranslate(pos);
			ofRotate(ang, vec.x, vec.y, vec.z);

			ofSetColor(255);
			ofNoFill();
			ofCircle(0,0,0,30);

			ofRotate(30,  1,1,0);       // rotate alittle bit, so you can see the "box" of the object
			ofSetColor(255,100);
	//		ofDrawSphere(0,0,0,60);
			ofDrawBox(0,0,0,60);
        ofPopMatrix();
    }
    
	
	
	// Draw plane
	ofSetColor(0, 250, 250, 100);
	plane.draw(OF_MESH_FILL);
	plane.drawAxes(100);
	
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}





















