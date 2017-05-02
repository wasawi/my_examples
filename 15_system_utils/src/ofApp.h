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
		string appname = ofFilePath::getCurrentExePath();
		vector <string> cleanString = ofSplitString(appname, ofFilePath::getCurrentWorkingDirectory()+"\\",true,true);
		appname = cleanString[0];
		return appname;
	}

	//--------------------------------------------------------------
	string ofGetAppPath(){
//		string appname = ofGetAppName()+"\n";
		string appPath = ofFilePath::getCurrentExePath();
		vector <string> cleanString = ofSplitString(appPath, "\n");
		appPath = cleanString[0];
		return appPath;
	}

	//--------------------------------------------------------------
	string ofGetCurrentPath(){
		string currentPath = ofFilePath::getCurrentWorkingDirectory();
		vector <string> cleanString = ofSplitString(currentPath, "\n");
		currentPath = cleanString[0];
		return currentPath;
	}
	
	//--------------------------------------------------------------
	void ofRestart(int type=0){
		ofLogNotice("ofRestart()")<<"restarting...";
		switch (type) {
			case 0:
#ifdef OF_TARGET_OSX
				ofSystem("open " + ofGetAppPath());
#endif // OF_TARGET_OSX
#ifdef TARGET_WIN32
				ofSystem("start " + ofGetAppPath());
#endif // TARGET_WIN32

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
					abort();					// crash immediately and message
					break;
			}
	}
	
	//--------------------------------------------------------------
	void ofKillApp(string appname){

		/*
		 http://www.linux.org/threads/kill-commands-and-signals.4423/
		 
		 SIGHUP (1) - Hangup detected on controlling terminal or death of controlling process. Use SIGHUP to reload configuration files and open/close log files.
		 SIGKILL (9) - Kill signal. Use SIGKILL as a last resort to kill process. This will not save data or cleaning kill the process.
		 SIGTERM (15) - Termination signal. This is the default and safest way to kill process.
		 */
		
		ofSystem("ps aux | grep "+appname+" | awk {'print $2'} | xargs KILL -9");
	}
	
	
};
