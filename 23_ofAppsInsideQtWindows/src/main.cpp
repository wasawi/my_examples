
#include "ofMain.h"
#include "ofApp.h"
//#include "GuiApp.h"

#include "ofAppQtWindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	/*//////////////////////////////
	//	multiwindow example
	////////////////////////////////
	
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

	shared_ptr<ofAppPtr> mainApp(new ofAppPtr);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	mainApp->QtGUI = guiApp;

	ofRunApp(guiWindow, guiApp);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
	//////////////////////////////*/

	/*//////////////////////////////
	//	QT multiwindow example 
	////////////////////////////////
	ofGLFWWindowSettings settings;

	settings.title = "Render 1";
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(500, 100));
	settings.resizable = true;
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	shared_ptr<ofAppPtr> app(new ofAppPtr);

	settings.title = "Render 2";
	settings.width = 300;
	settings.height = 300;
	settings.setPosition(ofVec2f(1100, 100));
	settings.resizable = false;
//	settings.decorated = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	app->QtGUI = guiApp;

    int argc = 0;
    char *argv[] = {0};
    QApplication a(argc, argv);
    MainWindow w;

//	ofAppPtr* app = new ofAppPtr();
    app->ui = w.ui;

    w.show();
//	a.exec(); //< this doesn't work for some reason

	ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, app);
	ofRunMainLoop();
	//////////////////////////////*/

		//ofAppGlutWindow window; // create a window
		//ofAppGLFWWindow window; // create a window
		//glfwWindowHint(GLFW_DECORATED, false);
		//ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);

/*	working ofAppQtWindow
	ofAppQtWindow* pWindow = new ofAppQtWindow();
	ofSetupOpenGL(pWindow, 600, 320, OF_WINDOW);
	shared_ptr<ofAppPtr> app = make_shared<ofAppPtr>();
//	shared_ptr<ofBaseApp> baseApp = app;
	MainWindow w;
	app->ui = w.ui;
	w.show();
	pWindow->run(app);
*/

	////////////////////////////////
	//	QT single window example
	////////////////////////////////
//	/*
//	ofAppQtWindow window;
	//	window.setMultiDisplayFullscreen(true);
//	ofSetupOpenGL(&window, 800, 400, OF_WINDOW);
//	ofRunApp(new ofApp);

//	*/
	// -- or
	/*
	shared_ptr<ofApp> app = make_shared<ofApp>();
	ofAppQtWindow window;
	ofSetupOpenGL(&window, 800, 400, OF_WINDOW);
	ofRunApp(app);
	*/

	//////////////////////////////////////
	// create Qt app
	//////////////////////////////////////
	QApplication *	qtAppPtr = new QApplication(argc, argv);
	MainWindow w;
	w.show();
	//shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>(qtAppPtr);
	//ofSetupOpenGL(mainWindow, 800, 400, OF_WINDOW);

	//// create app
	//shared_ptr<ofApp> mainApp(new ofApp);
	//ofRunApp(mainWindow, mainApp);

	return qtAppPtr->exec();

	/*
	////////////////////////////////
	//	QT multiwindow example			NOT WORKING.
	////////////////////////////////
	ofQtGLWindowSettings settings;

	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(300, 0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	settings.width = 300;
	settings.height = 300;
	settings.setPosition(ofVec2f(0, 0));
	settings.resizable = false;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<GuiApp> guiApp(new GuiApp);
	mainApp->QtGUI = guiApp;

	ofRunApp(guiWindow, guiApp);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
	*/

	
/*
	////////////////////////////////
	//	QT multiwindow example One App
	////////////////////////////////

	//////////////////////////////////////
	// create Qt app
	//////////////////////////////////////
	int argc = 1;
	char *argv = "openframeworks";
	char **vptr = &argv;
	QApplication *	qtAppPtr = new QApplication(argc, vptr);

	ofQtGLWindowSettings settings;
	settings.width = 600;
	settings.height = 600;
	settings.setPosition(ofVec2f(300,0));
	settings.resizable = true;
//	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
//	shared_ptr<ofAppBaseWindow> mainWindow = shared_ptr<ofAppQtWindow>(new ofAppQtWindow());
	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>(qtAppPtr);
	ofSetupOpenGL(mainWindow.get(), 800, 400, OF_WINDOW);

	settings.width = 300;
	settings.height = 300;
	settings.setPosition(ofVec2f(0,0));
	settings.resizable = false;
	// uncomment next line to share main's OpenGL resources with gui
	//settings.shareContextWith = mainWindow;	
//	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
//	shared_ptr<ofAppBaseWindow> guiWindow = shared_ptr<ofAppQtWindow>(new ofAppQtWindow());
	shared_ptr<ofAppQtWindow> guiWindow = make_shared<ofAppQtWindow>(qtAppPtr);
	ofSetupOpenGL(guiWindow.get(), 300, 300, OF_WINDOW);
	guiWindow->setVerticalSync(false);

	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->setupGui();
	ofAddListener(guiWindow->events().draw, mainApp.get(), &ofApp::drawGui);

	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
	*/

}
