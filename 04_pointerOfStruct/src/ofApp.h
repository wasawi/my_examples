#pragma once

#include "ofMain.h"

#define N_MOVIES 3

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
	
	// this is a structure that contains 2 objects
	struct movies_t {
		string title;
		int year;
	};
	
	movies_t amovie;
	movies_t * pmovie;
	
	// this is a fucntion that receives an structure as an argument
	void printmovie (movies_t* movie);
	
};
