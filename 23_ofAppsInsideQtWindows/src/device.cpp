#include "device.h"


//device::device( QWidget *parent)//shared_ptr<ofApp> _ofAppPtr,
device::device(QWidget *parent, shared_ptr<ofApp> _ofAppPtr)
	: QWidget(parent)
{
	ui.setupUi(this);

	// here we create a ofapp with an ofqtwindow
	// then we extract a pointer to QOpenGLWidget
	// and we inert it in the layout.


//	shared_ptr<ofApp> ofAppPtr(new ofApp);
//	shared_ptr<ofApp> ofAppPtrr(&ofAppPtr);
	ofAppPtr	= _ofAppPtr;

//	ofAppPtr	= make_shared<ofApp>();

//	loop = make_shared<ofMainLoop>();
//	loop = ofGetMainLoop();

	// create a window
	mainWindow = make_shared<ofAppQtWindow>(this->parentWidget());
	ofSetupOpenGL(mainWindow, 400, 400, OF_WINDOW);
//	shared_ptr<ofApp> mainApp(new ofApp);
//	ofRunApp(mainWindow, mainApp);
//	ofAppPtr = mainApp;

	/*
	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>(this->parentWidget());
	mainWindow->setAppPtr(ofAppPtr);
	*/
	
	// add widget to layout
	layout = ui.horizontalLayout;
	layout->addWidget(mainWindow->getQOpenGLWidget());
	ui.widget_2->setLayout(layout);

	timer = new QTimer(this);
//	connect(timer, &QTimer::timeout, [=]() { newframe(); });
	connect(timer, &QTimer::timeout, this, &device::newframe);


//	loop->run(mainWindow, std::move(ofAppPtr));
	ofRunApp(mainWindow, ofAppPtr);
//	ofRunApp(mainWindow, ofAppPtrr);
	ofGetMainLoop()->setShouldClose(false);

	timer->start(1);
}

device::~device()
{
	cout << "~device" << endl;

	timer->stop();
	timer->disconnect();

	mainWindow->setWindowShouldClose(true);
	ofGetMainLoop()->loopOnce();

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
	ofGetMainLoop()->loopOnce();
//	loop->loopOnce();
//	loop->run(mainWindow, std::move(ofAppPtr));

	// following does not work
//	ofGetMainLoop()->run(mainWindow, ofAppPtr);
//	ofRunApp(mainWindow, ofAppPtr);
}

void device::on_horizontalSlider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
//	ofAppPtr.radius.set(value);

}
