#pragma once

#include "ofConstants.h"
#include "ofAppBaseWindow.h"
#include <QApplication>
#include "window.h"

//class ofPoint;
class ofBaseApp;

//ofAppBaseWindow
//ofAppBaseGLWindow
//ofAppGlutWindow

class ofAppQtWindow : public ofAppBaseGLWindow {
	
public:

	ofAppQtWindow();
	~ofAppQtWindow();

	static bool doesLoop() { return true; }
	static bool allowsMultiWindow() { return false; }
	static void loop() {};
	static bool needsPolling() { return false; }
	static void pollEvents() {  }

	using ofAppBaseWindow::setup;
	void setup(const ofGLWindowSettings & settings);
	void update();
	void draw();

	//bool getWindowShouldClose();
	//void setWindowShouldClose();

	//void close();

	ofCoreEvents & events() override { return coreEvents; };
	shared_ptr<ofBaseRenderer> & renderer() override { return currentRenderer; };

	void initializeWindow();
	void run(shared_ptr<ofApp> appPtr);

	void hideCursor();
	void showCursor();

	void setFullscreen(bool fullScreen);
	void toggleFullscreen();

	static void exitApp();

	void setWindowTitle(string title);
	void setWindowPosition(int x, int y);
	void setWindowShape(int w, int h);

	glm::vec2		getWindowPosition();
	glm::vec2		getWindowSize();
	glm::vec2		getScreenSize();

	ofWindowMode	getWindowMode();

	int			getFrameNum();
	float		getFrameRate();
	void		setFrameRate(float targetRate);

	void		enableSetupScreen();
	void		disableSetupScreen();

	/*	
	static void display(void);
	static void mouse_cb(int button, int state, int x, int y);
	static void motion_cb(int x, int y);
	static void passive_motion_cb(int x, int y);
	static void idle_cb(void);
	static void keyboard_cb(unsigned char key, int x, int y);
	static void keyboard_up_cb(unsigned char key, int x, int y);
	static void special_key_cb(int key, int x, int y) ;
	static void special_key_up_cb(int key, int x, int y) ;
	static void resize_cb(int w, int h);
	*/

	ofWindowMode	windowMode;
	bool			bNewScreenMode;
	float			timeNow, timeThen, fps;
	int				nFramesForFPS;
	int				nFrameCount;
	int				buttonInUse;
	bool			bEnableSetupScreen;

	bool			bFrameRateSet;
	int 			millisForFrame;
	int 			prevMillis;
	int 			diffMillis;
	int				windowW, windowH;		// physical pixels width
	int				currentW, currentH;		// scaled pixels width

	//	float 			frameRate;

	int				requestedWidth;
	int				requestedHeight;
	int 			nonFullScreenX;
	int 			nonFullScreenY;
	int				mouseX, mouseY;
	shared_ptr<ofApp>	ofAppPtr;

	ofCoreEvents coreEvents;
	shared_ptr<ofBaseRenderer> currentRenderer;
	ofGLWindowSettings settings;


	//QT Stuff
	QApplication* qtApp;
	Window * window;

	void setStatusMessage(string s);
	//    Window window;
	//  window.show();
	// return app.exec();

};