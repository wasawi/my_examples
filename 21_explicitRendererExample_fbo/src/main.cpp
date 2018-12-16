#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){

//	ofInit();

	ofGLFWWindowSettings settings;

	settings.setSize(300, 300);
	settings.setPosition(ofVec2f(100, 40));
	settings.resizable = true;
	settings.numSamples = 8;
	ofMainLoop mainLoop;
	auto mainWindow = mainLoop.createWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);
	mainApp->window = mainWindow;
	mainApp->gl = static_pointer_cast<ofGLRenderer>(mainWindow->renderer());
	mainLoop.run(mainWindow, mainApp);

	//-------------------------------

	settings.setSize(windowWidth, windowHeight);
	settings.setPosition(ofVec2f(600, 40));
	settings.resizable = true;
	settings.numSamples = 8;
	settings.shareContextWith = mainWindow;
	ofMainLoop guiLoop;
	auto guiWindow = guiLoop.createWindow(settings);

	shared_ptr<GuiApp> guiApp(new GuiApp);
	guiApp->window = guiWindow;
	guiApp->gl = static_pointer_cast<ofGLRenderer>(guiWindow->renderer());
	guiLoop.run(guiWindow, guiApp);

	//-------------------------------

	while (!mainWindow->getWindowShouldClose()) {
		mainLoop.loopOnce();
		ofAppGLFWWindow::pollEvents();
		
		guiApp->setTextureId(mainApp->getTextureId());

		guiLoop.loopOnce();
		ofAppGLFWWindow::pollEvents();
	}
}

//-------------------------------
/*
bool t1Running = true;
auto t1 = std::thread([&] {
shared_ptr<ofApp> mainApp(new ofApp);
mainApp->window = mainWindow;
mainApp->gl = static_pointer_cast<ofGLRenderer>(mainWindow->renderer());
mainLoop.run(mainWindow, mainApp);

shared_ptr<GuiApp> guiApp(new GuiApp);
guiApp->window = guiWindow;
guiApp->gl = static_pointer_cast<ofGLRenderer>(guiWindow->renderer());
guiLoop.run(guiWindow, guiApp);

while (!mainWindow->getWindowShouldClose()) {
mainLoop.loopOnce();
guiLoop.loopOnce();
}
t1Running = false;
});

while (t1Running) {
ofAppGLFWWindow::pollEvents();
//		ofSleepMillis(1000 / 60);
}

t1.join();
*/

//-------------------------------
/*
bool t1Running = true;
auto t1 = std::thread([&] {
shared_ptr<ofApp> mainApp(new ofApp);
mainApp->window = mainWindow;
mainApp->gl = static_pointer_cast<ofGLRenderer>(mainWindow->renderer());
mainLoop.run(mainWindow, mainApp);

while (!mainWindow->getWindowShouldClose()) {
mainLoop.loopOnce();
}
t1Running = false;
});

ofSleepMillis(1000);

bool t2Running = true;
auto t2 = std::thread([&] {
shared_ptr<GuiApp> guiApp(new GuiApp);
guiApp->window = guiWindow;
guiApp->gl = static_pointer_cast<ofGLRenderer>(guiWindow->renderer());
guiLoop.run(guiWindow, guiApp);
while (!guiWindow->getWindowShouldClose()) {
guiLoop.loopOnce();
}
t2Running = false;
});

while (t1Running || t2Running) {
ofAppGLFWWindow::pollEvents();
ofSleepMillis(1000 / 60);
}
t1.join();
t2.join();
*/









/*
ofGLFWWindowSettings settings;

settings.width = 600;
settings.height = 600;
settings.setPosition(ofVec2f(300,0));
settings.resizable = true;
settings.numSamples = 8;
shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

settings.width = 300;
settings.height = 300;
settings.setPosition(ofVec2f(0,0));
settings.resizable = true;
settings.numSamples = 4;
settings.shareContextWith = mainWindow;
shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

shared_ptr<ofApp> mainApp(new ofApp);
shared_ptr<GuiApp> guiApp(new GuiApp);

mainApp->gui = guiApp;
mainApp->window = mainWindow;
mainApp->gl = dynamic_pointer_cast<ofBaseGLRenderer>(mainWindow->renderer());

ofRunApp(guiWindow, guiApp);
ofRunApp(mainWindow, mainApp);
ofRunMainLoop();
*/
