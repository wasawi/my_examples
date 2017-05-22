#include "device.h"


device::device(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// here we create a ofapp with an ofqtwindow
	// then we extract a pointer to QOpenGLWidget
	// and we inert it in the layout.

	// create app and window
	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<ofAppQtWindow> mainWindow = make_shared<ofAppQtWindow>(this->parentWidget());
	mainWindow->setAppPtr(mainApp);

	ofSetupOpenGL(mainWindow, 400, 400, OF_WINDOW);
	ofRunApp(mainWindow, mainApp);

	// add widget to layout
	QHBoxLayout *layout = ui.horizontalLayout;
	layout->addWidget(mainWindow->getQOpenGLWidget());
	ui.widget_2->setLayout(layout);


	//	QOpenGLWidget *w = new QOpenGLWidget(this);
//	connect(timer, SIGNAL(timeout()), w, SLOT(update()));
//	connect(timer, SIGNAL(timeout()), mainWindow.get(), SLOT(draw()));
//	connect(timer, &QTimer::timeout, mainWindow.get(), &ofAppQtWindow::update);
//	connect(timer, &QTimer::timeout, mainWindow.get(), &ofAppQtWindow::draw);
//	connect(&timer, &QTimer::timeout, loop.get(), &ofMainLoop::loopOnce);

	//	mainApp->setup();
	//	loop->loopOnce();
	//	ofRunMainLoop();

	QTimer *timer = new QTimer(this);
	shared_ptr<ofMainLoop> loop = ofGetMainLoop();
	connect(timer, &QTimer::timeout, [=]() {loop->loopOnce(); });

	timer->start(1);

//	ofRunApp(mainWindow, mainApp);
}

device::~device()
{
}
