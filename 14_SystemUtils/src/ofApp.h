#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
	int counter;
	ofImage img;
	int w,h;
	
	//--------------------------------------------------------------
	string ofGetUserName(){
		string username = ofSystem("whoami");
		vector <string> cleanString = ofSplitString(username, "\n");
		username = cleanString[0];
		return username;
	}
	
	//--------------------------------------------------------------
	string ofGetAppName(){
		string appname = ofSystem("ls ./");
		vector <string> cleanString = ofSplitString(appname, "\n");
		appname = cleanString[0];
		return appname;
	}

	//--------------------------------------------------------------
	string ofGetAppPath(){
		string appname = ofGetAppName()+"\n";
		string appPath = ofSystem("find `pwd` -name " + appname);
		vector <string> cleanString = ofSplitString(appPath, "\n");
		appPath = cleanString[0];
		return appPath;
	}

	//--------------------------------------------------------------
	string ofGetCurrentPath(){
		string currentPath = ofSystem("pwd");
		vector <string> cleanString = ofSplitString(currentPath, "\n");
		currentPath = cleanString[0];
		return currentPath;
	}
	
	//--------------------------------------------------------------
	void ofRestart(int type=0){
		ofLogNotice("ofRestart()")<<"restarting...";
		switch (type) {
			case 0:
				ofSystem("open " + ofGetAppPath());
				ofLogNotice("ofRestart()")<<"new app launched";
				ofExit();
				break;
			default:
				// not working well :/
//				string restart =ofGetAppPath()+" &";
//				ofSystem(restart);
//				ofLogNotice("ofRestart()")<<"new app launched";
//				ofExit();
				break;
			}
		ofLogNotice("ofRestart()")<<"out of reach"; // this will never print
	}

	//--------------------------------------------------------------
	void ofCrash(int type=0){
			switch (type) {
				case 0:
					abort();						// no message
					break;
				case 1:
					*((unsigned int*)0) = 0xDEAD;	// crash immediately and message
					break;
				default:
					raise(SIGSEGV);					// crash immediately and message
					break;
			}
	}

};
