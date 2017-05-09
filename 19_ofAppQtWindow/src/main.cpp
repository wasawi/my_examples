
#include "ofMain.h"
#include "ofApp.h"
//#include "GuiApp.h"

#include "ofAppQtWindow.h"
#include "mainwindow.h"

int main( )
{
	/* form multiwindow example
		ofGLFWWindowSettings settings;

	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(300,0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	settings.width = 300;
	settings.height = 300;
	settings.setPosition(ofVec2f(0,0));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	mainApp->gui = guiApp;

	ofRunApp(guiWindow, guiApp);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
	*/

	/*
	ofGLFWWindowSettings settings;

	settings.title = "Render 1";
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(500, 100));
	settings.resizable = true;
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	shared_ptr<ofApp> app(new ofApp);

	settings.title = "Render 2";
	settings.width = 300;
	settings.height = 300;
	settings.setPosition(ofVec2f(1100, 100));
	settings.resizable = false;
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	app->gui = guiApp;

    int argc = 0;
    char *argv[] = {0};
    QApplication a(argc, argv);
    MainWindow w;

//	ofApp* app = new ofApp();
    app->ui = w.ui;

    w.show();
//	a.exec(); //< this doesn't work for some reason

	ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, app);
	ofRunMainLoop();
	*/

		//ofAppGlutWindow window; // create a window
		//ofAppGLFWWindow window; // create a window
		//glfwWindowHint(GLFW_DECORATED, false);
		//ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);


	ofAppQtWindow* pWindow = new ofAppQtWindow();

	ofSetupOpenGL(pWindow, 600, 320, OF_WINDOW);			// <-------- setup the GL context

															// this kicks off the running of my app
															// can be OF_WINDOW or OF_FULLSCREEN
															// pass in width and height too:




	shared_ptr<ofApp> app = make_shared<ofApp>();
//	shared_ptr<ofBaseApp> baseApp = app;

	MainWindow w;
	app->ui = w.ui;
	w.show();

	pWindow->run(app);
	ofRunApp(app);
	ofRunMainLoop();
}
