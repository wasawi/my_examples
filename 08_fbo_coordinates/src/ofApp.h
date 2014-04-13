#pragma once

#include "ofMain.h"
#include "ofxGifEncoder.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	void storeMatrixOF();
	void storeMatrixGL();
	void loadMatrixOF();
	void loadMatrixGL();
	
	void ofLoadIdentity();
	void drawSomething();
	
	ofImage		img;
	ofEasyCam	cam;
	ofFbo		fbo;
	ofMatrix4x4 modelview;
	ofMatrix4x4 projection;
	GLfloat		modl[16], proj[16];
	
	// GIF
	ofxGifEncoder gifEncoder;
	void onGifSaved(string & fileName);
	void exit();
};


// fbos are flipped
// http://forum.openframeworks.cc/t/get-view-and-projection-matrices-of-vs-opengl/15046/5
