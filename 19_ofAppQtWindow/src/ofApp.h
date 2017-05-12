#pragma once

#include "ofMain.h"
#include "GuiApp.h"

#include "Controller.h"
#include "mainwindow.h"
#include <QSettings>

namespace Ui {
    class MainWindow;
}

class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
		void draw(int drawPlugin);

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

        int sliderInt;
        Ui::MainWindow *ui;
		
		ofColor color;
		ofPoint cursor;
		string key_str;

		shared_ptr<GuiApp> gui;

		void saveSettings(QSettings * settings);
		void loadSettings(QSettings * settings);

		Controller * controller;
		QSettings * settings;
//		QMainWindow * window;
		MainWindow * w;
};
