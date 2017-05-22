#include "ofAppQtWindow.h"

//----------------------------------------------------------
//ofAppQtWindow::ofAppQtWindow(QApplication * qtApp) {
ofAppQtWindow::ofAppQtWindow(QWidget *parent){
	bEnableSetupScreen = true;
	buttonPressed = false;
	bWindowNeedsShowing = true;
	buttonInUse = 0;
	iconSet = false;
	orientation = OF_ORIENTATION_DEFAULT;
	windowMode = OF_WINDOW;
	pixelScreenCoordScale = 1;
	nFramesSinceWindowResized = 0;
	windowW = 0;
	windowH = 0;
	currentW = 0;
	currentH = 0;

	//// if not created in main.cpp create Qt app 
	//if (qtApp == 0) {
	//	int argc = 1;
	//	char *argv = "openframeworks";
	//	char **vptr = &argv;
	//	qtAppPtr = new QApplication(argc, vptr);
	//}
	//else {
	//	qtAppPtr = qtApp;
	//}

	if (parentWidget == 0) {
		parentWidget = nullptr;
	}
	else {
		parentWidget = parent;
	}
	ofAppPtr = nullptr;
	windowPtr = nullptr;
}

//----------------------------------------------------------
ofAppQtWindow::~ofAppQtWindow() {
	close();
}

//------------------------------------------------------------
#ifdef TARGET_OPENGLES
void ofAppGLFWWindow::setup(const ofGLESWindowSettings & settings) {
#else
void ofAppQtWindow::setup(const ofGLWindowSettings & settings) {
#endif
	const ofQtGLWindowSettings * glSettings = dynamic_cast<const ofQtGLWindowSettings*>(&settings);
	if (glSettings) {
		setup(*glSettings);
	}
	else {
		setup(ofQtGLWindowSettings(settings));
	}
}

//------------------------------------------------------------
void ofAppQtWindow::setup(const ofQtGLWindowSettings & _settings) {
	cout << "setup ofAppQtWindow" << endl;

	if (windowPtr) {
		ofLogError() << "window already setup, probably you are mixing old and new style setup";
		ofLogError() << "call only ofCreateWindow(settings) or ofSetupOpenGL(...)";
		ofLogError() << "calling window->setup() after ofCreateWindow() is not necesary and won't do anything";
		return;
	}
	settings = _settings;


	//////////////////////////////////////
	// setup OpenGL
	//////////////////////////////////////
	QSurfaceFormat format;
	format.setVersion(settings.glVersionMajor, settings.glVersionMinor);
	format.setProfile(QSurfaceFormat::CoreProfile);
	format.setAlphaBufferSize(settings.alphaBits);
	format.setDepthBufferSize(settings.depthBits);
	format.setStencilBufferSize(settings.stencilBits);
	format.setStereo(settings.stereo);
	format.setSamples(settings.numSamples);
	if (settings.doubleBuffering) {
		format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
	}
	else {
		format.setSwapBehavior(QSurfaceFormat::SingleBuffer);
	}
	QSurfaceFormat::setDefaultFormat(format);

	//////////////////////////////////////
	// create renderer
	//////////////////////////////////////
	if (settings.glVersionMajor >= 3) {
		currentRenderer = shared_ptr<ofBaseRenderer>(new ofGLProgrammableRenderer(this));
	}
	else {
		currentRenderer = shared_ptr<ofBaseRenderer>(new ofGLRenderer(this));
	}

	//////////////////////////////////////
	// create Qt window
	//////////////////////////////////////
	windowPtr = new QtGLWidget(this, parentWidget);
	windowPtr->resize(settings.width, settings.height);
//	windowPtr->setFormat(format);
//	windowPtr->setWindowTitle(settings.title);
	//	currentW = windowPtr->size().width();
	//	currentH = windowPtr->size().height();
	windowW = settings.width;
	windowH = settings.height;
	bWindowNeedsShowing = settings.visible;
//	windowPtr->setAlphabits(settings.alphaBits);
//	windowPtr->setNumSamples(settings.numSamples);
	windowPtr->makeCurrent();
	windowPtr->show();

//	int framebufferW, framebufferH;
//	glfwGetFramebufferSize(windowPtr, &framebufferW, &framebufferH);

	//this lets us detect if the window is running in a retina mode
	//if (framebufferW != windowW) {
	//	pixelScreenCoordScale = framebufferW / windowW;

	//	auto position = getWindowPosition();
	//	setWindowShape(windowW, windowH);
	//	setWindowPosition(position.x, position.y);
	//}


#ifndef TARGET_OPENGLES
	static bool inited = false;
	if (!inited) {
		glewExperimental = GL_TRUE;
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			/* Problem: glewInit failed, something is seriously wrong. */
			ofLogError("ofAppRunner") << "couldn't init GLEW: " << glewGetErrorString(err);
			return;
		}
		inited = true;
	}
#endif

	ofLogVerbose() << "GL Version:" << glGetString(GL_VERSION);

	//////////////////////////////////////
	// setup renderer
	//////////////////////////////////////
	if (currentRenderer->getType() == ofGLProgrammableRenderer::TYPE) {
#ifndef TARGET_OPENGLES
		static_cast<ofGLProgrammableRenderer*>(currentRenderer.get())->setup(settings.glVersionMajor, settings.glVersionMinor);
#else
		static_cast<ofGLProgrammableRenderer*>(currentRenderer.get())->setup(settings.glesVersion, 0);
#endif
	}
	else {
		static_cast<ofGLRenderer*>(currentRenderer.get())->setup();
	}

	//events().notifySetup();

	//////////////////////////////////////
	// notes
	//////////////////////////////////////
	// this call goes to an endless loop 
	// which causes no OF calls
//	qtAppPtr->exec();
	// we will use 
//	qtAppPtr->processEvents();
	// so that we can call qt inside the OF loop
}
//------------------------------------------------------------
void ofAppQtWindow::update() {
//	cout << "update ofAppQtWindow" << endl;
	events().notifyUpdate();

	//////////////////////////////////////
	// process Qt events
	//////////////////////////////////////
	windowPtr->makeCurrent();
	windowPtr->update();
//	ofAppPtr->update();

	//////////////////////////////////////

	//show the window right before the first draw call.
	if (bWindowNeedsShowing && windowPtr) {
		// GLFW update was here
		bWindowNeedsShowing = false;
		if (settings.windowMode == OF_FULLSCREEN) {
			setFullscreen(true);
		}
	}
}
//------------------------------------------------------------
void ofAppQtWindow::draw() {
//	cout << "draw ofAppQtWindow" << endl;
	currentRenderer->startRender();

	if (bEnableSetupScreen) currentRenderer->setupScreen();

	events().notifyDraw();

#ifdef TARGET_WIN32
	if (currentRenderer->getBackgroundAuto() == false) {
		// on a PC resizing a window with this method of accumulation (essentially single buffering)
		// is BAD, so we clear on resize events.
		if (nFramesSinceWindowResized < 3) {
			currentRenderer->clear();
		}
		else {
			if ((events().getFrameNum() < 3 || nFramesSinceWindowResized < 3) && settings.doubleBuffering) {
				//////////////////////////////////////
				// process Qt events
				//////////////////////////////////////
//				windowPtr->swapBuffers();
//				qtAppPtr->processEvents();
//				ofAppPtr->draw();
			}
			else {
				glFlush();
			}
		}
	}
	else {
		if (settings.doubleBuffering) {
			//////////////////////////////////////
			// process Qt events
			//////////////////////////////////////
//			windowPtr->swapBuffers();
//			qtAppPtr->processEvents();
//			windowPtr->makeCurrent();
//			ofAppPtr->draw();
			windowPtr->update();
		}
		else {
			glFlush();
		}
	}
#else
	if (currentRenderer->getBackgroundAuto() == false) {
		// in accum mode resizing a window is BAD, so we clear on resize events.
		if (nFramesSinceWindowResized < 3) {
			currentRenderer->clear();
		}
	}
	if (settings.doubleBuffering) {
		glfwSwapBuffers(windowP);
	}
	else {
		glFlush();
	}
#endif
	

	currentRenderer->finishRender();

	nFramesSinceWindowResized++;
}
//
//void ofAppQtWindow::paintEvent(QPaintEvent * event)
//{
//	cout << "paint event" << endl;
////	draw();
//}

//------------------------------------------------------------
ofCoreEvents & ofAppQtWindow::events() {
	return coreEvents;
}

//------------------------------------------------------------
shared_ptr<ofBaseRenderer> & ofAppQtWindow::renderer() {
	return currentRenderer;
}

QOpenGLWidget * ofAppQtWindow::getQOpenGLWidget()
{
	return windowPtr;
}

//------------------------------------------------------------
void ofAppQtWindow::setAppPtr(shared_ptr<ofApp> appPtr){
	ofAppPtr = appPtr;
}

//------------------------------------------------------------
void ofAppQtWindow::setStatusMessage(string s) {
}

//------------------------------------------------------------
void ofAppQtWindow::exitApp() {
	ofLog(OF_LOG_VERBOSE, "QT OF app is being terminated!");
	OF_EXIT_APP(0);
}

////------------------------------------------------------------
//float ofAppQtWindow::getFrameRate() {
//	return windowPtr->getGlFrameRate();
//}

//------------------------------------------------------------
void ofAppQtWindow::setWindowTitle(string title) {
	settings.title = title;
	windowPtr->setWindowTitle(title);
}

//------------------------------------------------------------
glm::vec2 ofAppQtWindow::getWindowSize() {
	int width = windowPtr->width();
	int height = windowPtr->height();

	return glm::vec2(width, height);
}

//------------------------------------------------------------
glm::vec2 ofAppQtWindow::getWindowPosition() {
	int x = windowPtr->pos().x();
	int y = windowPtr->pos().y();

	cout << "getWindowPosition "<< x <<" "<< y << endl;
	return glm::vec2{ x, y };
}

//------------------------------------------------------------
glm::vec2 ofAppQtWindow::getScreenSize() {
	int width = windowPtr->size().width();
	int height = windowPtr->size().height();

	cout << "getScreenSize " << width << " " << height << endl;
	return glm::vec2{ width, height };
}

//------------------------------------------------------------
void ofAppQtWindow::setWindowPosition(int x, int y) {
	cout << "setWindowPosition " << x << " " << y << endl;
	windowPtr->move(QPoint{ x, y });
}

//------------------------------------------------------------
void ofAppQtWindow::setWindowShape(int w, int h) {

	if (windowMode == OF_WINDOW) {
		windowW = w;
		windowH = h;
	}
	currentW = w / pixelScreenCoordScale;
	currentH = h / pixelScreenCoordScale;

#ifdef TARGET_OSX
	auto pos = getWindowPosition();
	windowP->resize(currentW, currentH);
	if (pos != getWindowPosition()) {
		setWindowPosition(pos.x, pos.y);
	}
#else
	cout << "setWindowShape " << currentW << " " << currentH << endl;
	windowPtr->resize(currentW, currentH);
#endif
}

void ofAppQtWindow::close()
{
	events().disable();
	bWindowNeedsShowing = true;
}

//------------------------------------------------------------
void ofAppQtWindow::hideCursor() {
	windowPtr->unsetCursor();
}

//------------------------------------------------------------
void ofAppQtWindow::showCursor() {
	showCursor();
}

//------------------------------------------------------------
ofWindowMode ofAppQtWindow::getWindowMode() {
	return windowMode;
}

//------------------------------------------------------------
void ofAppQtWindow::enableSetupScreen() {
	bEnableSetupScreen = true;
}

//------------------------------------------------------------
void ofAppQtWindow::disableSetupScreen() {
	bEnableSetupScreen = false;
}

void ofAppQtWindow::makeCurrent()
{
	// used
	windowPtr->makeCurrent();
}

void ofAppQtWindow::swapBuffers()
{
	//unused
//	windowPtr->swapBuffers();
}

void ofAppQtWindow::startRender()
{
	//unused
//	renderer()->startRender();
}

void ofAppQtWindow::finishRender()
{
	//unused
//	renderer()->finishRender();
}
