#pragma once

#include "ofMain.h"
#include "Simple_fbo.h"

#define windowWidth 800
#define windowHeight 600


class ofApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

        // member variables to store the current mouse X and Y position 
        // as a percentage of the width/height of the screen
        float mouseXPercent, mouseYPercent;

		int width = 300;
		int height = 300;

		Simple_fbo fbo;
};
	
