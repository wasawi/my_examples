#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
	
	// this is an integer variable
	int age;
	
	// this is a pointer to an integer
	int* ages;
	
	// this is a function with a pointer as an argument
	void increase (void* data, int psize);
	void testFunction();
};
