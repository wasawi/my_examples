#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	int w	= 200;
	int h	= 200;

	ofPixels red, green;
	red.allocate(w, h, OF_IMAGE_COLOR_ALPHA);
	red.setColor(ofColor::red);
	
	green.allocate(w, h, OF_IMAGE_COLOR_ALPHA);
	green.setColor(ofColor::green);

	img1.setFromPixels(red);
	img2.setFromPixels(green);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(230); // this matters
	img1.draw(0,0);//red image
	img2.draw(100,100);//green image

	ofEnableBlendMode(OF_BLENDMODE_ADD);
	img1.draw(0,0);//red image
	img2.draw(100,100);//green image
	ofDisableAlphaBlending();


/* mike's solution
	ofBackground(230); // this matters
	img1.draw(0,0); // Draw red image without blend mode - i.e. overrides the background pixels
	ofEnableBlendMode(OF_BLENDMODE_ADD);  // this only applies to img2
	img2.draw(100,100); // Draw green image with a blend mode - i.e. using add, blend it into img1
	ofDisableBlendMode();  // Switch back to not using a blend mode
*/
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
