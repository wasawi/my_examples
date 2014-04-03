#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	void drawLabels();
	
	void keyPressed  (int key);
	
	ofEasyCam cam;
	
	ofPlanePrimitive plane;	// the plane to display
};