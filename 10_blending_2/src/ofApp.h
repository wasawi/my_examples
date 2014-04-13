#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawCircle();
		void drawCircleFBO();
	
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	ofFbo fbo;
	
};



// solving this thread:
// http://forum.openframeworks.cc/t/opengl-add-blend-mode-on-frame-buffer/15315

/*
//--------------------------------------------------------------
void ofApp::draw(){
	
	// Draw directly to screen
	drawCircle();
	
    // Draw to fbo
    fbo.begin();
	drawCircle();
    fbo.end();
	fbo.draw(ofGetWidth()/2, 0);
}
*/