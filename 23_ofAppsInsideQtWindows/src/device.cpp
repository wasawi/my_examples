#include "device.h"


device::device( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
//device::device(QWidget *parent, shared_ptr<ofApp> _ofAppPtr)
	: QWidget(parent)
{
	ui.setupUi(this);

	// here we create a ofapp with an ofqtwindow
	// then we extract a pointer to QOpenGLWidget
	// and we inert it in the layout.


//	shared_ptr<ofApp> ofAppPtr(new ofApp);
//	shared_ptr<ofApp> ofAppPtrr(&ofAppPtr);
//	ofAppPtr	= _ofAppPtr;
//	shared_ptr<ofApp> mainApp(new ofApp);
//	ofRunApp(windowPtr, mainApp);
//	ofAppPtr = mainApp;
//	shared_ptr<ofAppQtWindow> windowPtr = make_shared<ofAppQtWindow>(this->parentWidget());
//	windowPtr->setAppPtr(ofAppPtr);
//	loop = make_shared<ofMainLoop>();
//	loop = ofGetMainLoop();
//	shared_ptr<ofApp> ofAppPtr(new ofApp);
//	ofInit();
//	ofAppPtr->window = windowPtr;
//	ofAppPtr->gl = static_pointer_cast<ofGLRenderer>(windowPtr->renderer());
//	loop->addWindow(windowPtr);
//	gl = static_pointer_cast<ofGLRenderer>(windowPtr->renderer());
//	gl = make_shared<ofGLRenderer>(windowPtr.get());
//	windowPtr->renderer() = gl;
//	windowPtr->setup(windowPtr->getSettings());
//	loop = ofGetMainLoop();
//	loop->run(windowPtr, std::move(ofAppPtr));
//	ofRunApp(windowPtr, ofAppPtr);
//	ofRunApp(windowPtr, ofAppPtrr);
//	ofGetMainLoop()->setShouldClose(false);

	// create a window
	loop = make_shared<ofMainLoop>();
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>(this->parentWidget());
//	gl = static_pointer_cast<ofGLRenderer>(windowPtr->renderer());

	ofSetMainLoop(loop);
	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);
//	ofSetCurrentRenderer(gl);

	ofRunApp(windowPtr, ofAppPtr);
//	loop->run(windowPtr, ofAppPtr);

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(windowPtr->getQOpenGLWidget());
	ui.widget_2->setLayout(layout);

	timer = new QTimer(this);
//	connect(timer, &QTimer::timeout, [=]() { newframe(); });
	connect(timer, &QTimer::timeout, this, &device::newframe);

	timer->start(1);
}

device::~device()
{
	cout << "~device" << endl;

	timer->stop();
	timer->disconnect();

	/* to close a window in case we have one single loop for all:
	//	ofExit();//this is wrong
//	windowPtr->setWindowShouldClose(true);
//	ofGetMainLoop()->loopOnce();
//	loop->loopOnce();
	*/

	/* to debug ofMainLoop.cpp
	cout << "windowsApps.size " << windowsApps.size() << endl;
	for(auto i = windowsApps.begin(); !windowsApps.empty() && i != windowsApps.end();){
	cout << "current window should close " << i->first->getWindowShouldClose() << endl;
	if(i->first->getWindowShouldClose()){
	*/
}

void device::newframe()
{
	cout << "nf" << endl;
//	ofGetMainLoop()->loopOnce();
	loop->loopOnce();
}

void device::on_horizontalSlider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
//	ofAppPtr.radius.set(value);

}
void device::on_horizontalSlider_2_sliderMoved(int value) {
//	ofSetFrameRate(value);
//	windowPtr->events().setFrameRate(value);

	timer->setInterval(1000 / value);
}