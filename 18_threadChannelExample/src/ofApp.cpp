#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grabber.allocate(ofGetScreenWidth(), ofGetScreenHeight(), OF_IMAGE_COLOR);
	ofSetBackgroundColor(ofColor::white);
	ofSetColor(255);
	counter = 0;
	ofSetVerticalSync(false);
	ofSetFrameRate(framerate);

	updatePositions();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (counter < 1000) {
		counter++;
	}
	else {
		updatePositions();
		counter = 0;
	}
}

void ofApp::updatePositions() {
	positions.clear();
	for (int i = 0; i < 255; i++) {
		positions.push_back(
			ofPoint(ofRandom(ofGetWindowWidth() - margin * 2 - size) + margin,
				ofRandom(ofGetWindowHeight() - margin * 2 - size) + margin));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// draw rects
	ofPushStyle();
	ofFill();
	for (int i = 0; i < positions.size(); i++) {
		ofSetColor(i);
		ofRect(positions[i].x, positions[i].y, size, size);
	}
	ofPopStyle();

	grabber.grabScreen(ofGetMouseX(), ofGetMouseY(), 320, 240);
	grabber.update();
	analyzer.analyze(grabber.getPixels());
	analyzer.update();

	ofPushStyle();
		ofNoFill();
		ofSetColor(ofColor::red, 100);
		ofRect(ofGetMouseX(), ofGetMouseY(), 320, 240);
	ofPopStyle();

	grabber.draw(320,0);
	analyzer.draw(640,0);

	ofDrawBitmapStringHighlight("'c' clear Queue " + ofToString(analyzer.bClearQueue), ofPoint(0, 20));
	ofDrawBitmapStringHighlight("'i/o' framerate " + ofToString(ofGetFrameRate()), ofPoint(0, 40));
	ofDrawBitmapStringHighlight("'k/l' fake process time " + ofToString(analyzer.processTime), ofPoint(0, 60));
	ofDrawBitmapStringHighlight("toAnalyze_queueSize " + ofToString(analyzer.toAnalyze_queueSize), ofPoint(0, 80));
	ofDrawBitmapStringHighlight("analyzed_queueSize " + ofToString(analyzer.analyzed_queueSize), ofPoint(0, 100));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'c':
		analyzer.bClearQueue = !analyzer.bClearQueue;
		break;

	case 'i':
		if (framerate > 0) framerate -= 10;
		ofSetFrameRate(framerate);
		break;
	case 'o':
		framerate += 10;
		ofSetFrameRate(framerate);
		break;

	case 'k':
		if (analyzer.processTime > 0) analyzer.processTime -= 10;
		break;
	case 'l':
		analyzer.processTime += 10;
		break;
	}

	cout << framerate << endl;
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
