#pragma once

#include "ofMain.h"
#include "ImgAnalysisThread.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage grabber;
		ImgAnalysisThread analyzer;
		vector<ofPoint> positions;
		
		int counter;
		int margin = 10;
		int size = 100;
		int framerate = 60;
		
		void updatePositions();

};
