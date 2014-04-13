#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableSmoothing();
	ofEnableDepthTest();

	//fbo
	fbo.allocate(ofGetWidth()/2, ofGetHeight(), GL_RGBA);
	//img
	img.loadImage("chilis.jpg");

	// GIF
	gifEncoder.setup(ofGetWidth(), ofGetHeight(), 0.02, 255);
    ofAddListener(ofxGifEncoder::OFX_GIF_SAVE_FINISHED, this, &ofApp::onGifSaved);
}

//--------------------------------------------------------------
void ofApp::update(){
	// GIF
	gifEncoder.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	//-----------------------------------
	// draw to screen
	cam.begin();
	ofTranslate(-ofGetWidth()/4, 0);
	storeMatrixOF();
//	storeMatrixGL();
	drawSomething();
//	cam.end();

	//-----------------------------------
    // draw to fbo
	fbo.begin();
	loadMatrixOF();
//	loadMatrixGL();	//does the same thing
//	ofScale(1, -1, 1);
	drawSomething();
	fbo.end();
	cam.end();
	
	//-----------------------------------
    // draw the fbo to screen
	fbo.draw(ofGetWidth()/2,0,ofGetWidth(),ofGetHeight());
	// or draw upsidedown
//	fbo.draw(ofGetWidth()/2,ofGetHeight(),ofGetWidth(),-ofGetHeight());
	
	ofLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::drawSomething(){
	ofClear(ofColor::black);
	img.draw(0,0,img.getWidth(),img.getHeight());
	ofDrawAxis(100);
}

//--------------------------------------------------------------
void ofApp::storeMatrixOF() {
	// store OF matricies
	modelview = ofGetCurrentMatrix(OF_MATRIX_MODELVIEW);
	projection = ofGetCurrentMatrix(OF_MATRIX_PROJECTION);
}

//--------------------------------------------------------------
void ofApp::storeMatrixGL() {
	// store GL matricies
	glGetFloatv( GL_MODELVIEW_MATRIX, modl);
	glGetFloatv(GL_PROJECTION_MATRIX, proj);
}

//--------------------------------------------------------------
void ofApp::loadMatrixOF() {
	//load OF matricies from outside the FBO
	ofSetMatrixMode(OF_MATRIX_PROJECTION);
	ofLoadMatrix(projection);
	ofSetMatrixMode(OF_MATRIX_MODELVIEW);
	ofLoadMatrix(modelview);
}

//--------------------------------------------------------------
void ofApp::loadMatrixGL() {
	//load GL matricies from outside the FBO
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(proj);
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(modl);
}


//--------------------------------------------------------------
void ofApp::ofLoadIdentity() {
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW_MATRIX);
    glLoadIdentity();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	switch(key)
    {
		case ' ':
			//			gifEncoder.toggleRecording();
			break;
		case 's':
			cout << "Start saving..." << endl;
			string date;
			date=ofGetTimestampString();
			//			gifEncoder.save(date+".gif");
			break;
	}
	
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
//--------------------------------------------------------------
void ofApp::exit(){
    gifEncoder.exit();
}


//--------------------------------------------------------------
void ofApp::onGifSaved(string &fileName) {
    cout << "gif saved as " << fileName << endl;
	gifEncoder.reset();
}

