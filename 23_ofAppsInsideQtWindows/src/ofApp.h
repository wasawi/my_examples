#pragma once

#include "ofMain.h"
#include "GuiApp.h"
#include "ofxGui.h"

#include "Controller.h"
#include "mainwindow.h"
#include <QSettings>

namespace Ui {
    class MainWindow;
}

class ofApp : public ofBaseApp{
public:
//	ofApp();
	~ofApp();

        void setup();
        void update();
        void draw();
		void setupGui();
		void drawGui(ofEventArgs & args);

        void keyPressed(ofKeyEventArgs& key);
        void keyReleased(ofKeyEventArgs& key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

        //Ui::MainWindow *ui;
		
		ofPoint cursor;
		string key_str;

//		shared_ptr<GuiApp> QtGUI;

		void saveSettings(QSettings * settings);
		void loadSettings(QSettings * settings);

		Controller * controller;
		QSettings * settings;
//		QMainWindow * window;
//		MainWindow * w;

		ofParameterGroup parameters;
		ofParameter<float> radius;
		ofParameter<ofColor> color;
		ofParameter<float> framerate;
		ofParameter<bool> verticalSync;
		ofxPanel OfGUI;

		void setFramerate(float& value);
		void setVerticalSync(bool& value);
};
