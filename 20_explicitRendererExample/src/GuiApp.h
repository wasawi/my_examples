#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class GuiApp: public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

//	ofParameterGroup parameters;
//	ofParameter<float> radius;
//	ofParameter<ofColor> color;
//	ofxPanel gui;

	shared_ptr<ofAppBaseWindow> window;
	shared_ptr<ofBaseGLRenderer> gl;
	ofTrueTypeFont mainFont;
	ofSpherePrimitive sphere;
	ofEasyCam camera;
};

