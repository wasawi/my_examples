#include "device.h"


device::device( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
	: QWidget(parent)
{
	ui.setupUi(this);

	// here we create a ofapp with an ofqtwindow
	// then we extract a pointer to QOpenGLWidget
	// and we inert it in the layout.

	// create an app a loop and a window
	loop = make_shared<ofMainLoop>();
	ofAppPtr = make_shared<ofApp>();
	windowPtr = make_shared<ofAppQtWindow>(this->parentWidget());
	ofAppPtr->window = windowPtr;

	// initialize the window
	ofSetMainLoop(loop);
	ofSetupOpenGL(windowPtr, 400, 400, OF_WINDOW);

	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(windowPtr->getQOpenGLWidget());
	ui.widget_2->setLayout(layout);
	windowPtr->getQOpenGLWidget()->resized();

	// initialize OF
	ofRunApp(windowPtr, ofAppPtr);

	timer = new QTimer(this);
//	connect(timer, &QTimer::timeout, [=]() { newframe(); });
	connect(timer, &QTimer::timeout, this, &device::newframe);

	timer->start(10);
}

device::~device()
{
	cout << "~device" << endl;

	//timer->stop();
	//timer->disconnect();

	/* to debug ofMainLoop.cpp
	cout << "windowsApps.size " << windowsApps.size() << endl;
	for(auto i = windowsApps.begin(); !windowsApps.empty() && i != windowsApps.end();){
	cout << "current window should close " << i->first->getWindowShouldClose() << endl;
	if(i->first->getWindowShouldClose()){
	*/
}

void device::newframe()
{
//	cout << "newframe" << endl;
//	ofGetMainLoop()->loopOnce();
	ofGetMainLoop()->setCurrentWindow(windowPtr);
	loop->loopOnce();
}

void device::on_horizontalSlider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}
void device::on_horizontalSlider_2_sliderMoved(int value) {
//	ofSetFrameRate(value);
//	windowPtr->events().setFrameRate(value);
	timer->setInterval(1000 / value);
}