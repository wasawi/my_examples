#pragma once

#include "ofMain.h"
#include "GuiApp.h"

#include "Controller.h"
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

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

        int circleRadius;
        Ui::MainWindow *ui;
		ofColor color;

		shared_ptr<GuiApp> gui;

		void saveSettings(QSettings * settings);
		void loadSettings(QSettings * settings);

		Controller * controller;
		QSettings * settings;
		QMainWindow * window;
};
