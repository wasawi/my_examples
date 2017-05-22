#include "device.h"


device::device(shared_ptr<ofApp> _ofAppPtr, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// here we create a ofapp with an ofqtwindow
	// then we extract a pointer to QOpenGLWidget
	// and we inert it in the layout.

	// create app and window
//	shared_ptr<ofApp> ofAppPtr(new ofApp);
//	shared_ptr<ofApp> ofAppPtr(_ofAppPtr);
	ofAppPtr = _ofAppPtr;
	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>(this->parentWidget());
	mainWindow->setAppPtr(ofAppPtr);

	ofSetupOpenGL(mainWindow, 400, 400, OF_WINDOW);
	ofRunApp(mainWindow, ofAppPtr);

	// add widget to layout
	QHBoxLayout *layout = ui.horizontalLayout;
	layout->addWidget(mainWindow->getQOpenGLWidget());
	ui.widget_2->setLayout(layout);

	QTimer *timer = new QTimer(this);
	shared_ptr<ofMainLoop> loop = ofGetMainLoop();
	connect(timer, &QTimer::timeout, [=]() {loop->loopOnce(); });

	timer->start(1);
}

device::~device()
{
}

void device::on_horizontalSlider_sliderMoved(int value) {
	ofAppPtr->radius.set(value);
}
