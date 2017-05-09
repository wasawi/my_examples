
#include "glwidget.h"
#include "window.h"
#include <QtGui>

//! [0]

void Window::setApp(shared_ptr<ofApp> app){
	app = app;
	glWidget->ofApp = app;
}

int Window::getGlWidth(){
	return glWidget->width();
}
int Window::getGlHeight(){
	return glWidget->height(); 
}
float Window::getGlFrameRate(){
	return glWidget->frameRate;

}

Window::Window(shared_ptr<ofApp> _app)
{
	
	QWidget * content = new QWidget();

	app = _app;
	tab = new QTabWidget;
	viewCombo = new QComboBox();

    glWidget = new GLWidget(app);
	glWidget->setFixedWidth(500);
	glWidget->setFixedHeight(500);
	
//	content->setFixedWidth(500);
//	content->setFixedHeight(500);
	
	glWidget->tab = tab;
	glWidget->viewCombo = viewCombo;
	
	QTimer *timer = new QTimer(this);
    timer->setInterval(20);
	QObject::connect(timer, SIGNAL(timeout()), glWidget, SLOT(update()));
	QObject::connect(timer, SIGNAL(timeout()), glWidget, SLOT(updateGL()));
	timer->start();
	
    setWindowTitle(tr("GUI Shell"));
	
	QTimer *settingsTimer = new QTimer(this);
    settingsTimer->setInterval(1000);
	QObject::connect(settingsTimer, SIGNAL(timeout()), this, SLOT(saveSettings()));
	settingsTimer->start();


	
	
	//GENERAL SETTINGS TAB
	QLabel *fpsLabel = new QLabel(tr("FPS"));
	
	QWidget *settingsGroupBox = new QWidget();
	QGridLayout *settingsGrid = new QGridLayout;
	settingsGrid->setAlignment(Qt::AlignTop);
	settingsGrid->addWidget(new QLabel(tr("FPS:")), 0, 0);
	settingsGrid->addWidget(fpsLabel, 0,1);
	settingsGrid->setColumnStretch(1,20);
	settingsGroupBox->setLayout(settingsGrid);
	
	//tab->addTab(settingsGroupBox, "General");
	
	/*
	QDockWidget *dockWidget = new QDockWidget(tr("General"), this);
	dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
								Qt::RightDockWidgetArea);
	dockWidget->setWidget(settingsGroupBox);*/
	//addDockWidget(Qt::RightDockWidgetArea, dockWidget);
	
	setTabPosition(Qt::RightDockWidgetArea,QTabWidget::East);

	
	

	//SETUP MAIN LAYOUT
    QHBoxLayout *mainLayout = new QHBoxLayout;
	QWidget *glGroupBox = new QWidget();
	QVBoxLayout *glLayout = new QVBoxLayout;
	
	
	glGroupBox->setLayout(glLayout);
	glLayout->addWidget(viewCombo);
	glLayout->addWidget(glWidget);
	glLayout->setAlignment(Qt::AlignTop);
	
	mainLayout->addWidget(glGroupBox);
//	mainLayout->addWidget(tab);
	
    content->setLayout(mainLayout);
	
	setCentralWidget(content);
	
	
	//GENERAL EVENT CONNECTIONS
	//connect(xSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setXRotation(int))); //This line connects the x slider to the testApp
   // connect(rotateSlider, SIGNAL(valueChanged(int)), glWidget, SLOT(setRotateSlider(int)));
	connect(glWidget, SIGNAL(frameRateChanged(double)), fpsLabel, SLOT(setNum(double)));
	//connect(tabLayout, SIGNAL(valueChanged(int)), glWidget, SLOT(setXRotation(int)));

	settings = new QSettings("BrandtsRobot", "Illutron");
	
	setUnifiedTitleAndToolBarOnMac(true);
	
	////lock = new QAction(QIcon(QString(ofToDataPath("lock.png", true).c_str())), tr("Lock"),this);
	////lock->setShortcut( QKeySequence(Qt::ControlModifier + Qt::Key_L));

	////QObject::connect(lock, SIGNAL(triggered()), this, SLOT(toggleLock()));

	////toolbar = addToolBar(tr("Toolbar"));
	////setIconSize(QSize(20,20));
	////toolbar->addAction(lock);
	////statusBar()->showMessage(tr("Locked"));
	
	setDockOptions(QMainWindow::AnimatedDocks | QMainWindow::AllowTabbedDocks | QMainWindow::AllowNestedDocks);

}
void Window::saveSettings()
{
//	app->saveSettings(settings);
	settings->setValue("mainwindow/size", size());
	settings->setValue("mainwindow/pos", pos());
//	settings->setValue("maintab/index", tab->currentIndex());
	settings->setValue("viewCombo/index", viewCombo->currentIndex());
	settings->setValue("layout/state", 	saveState());
}

void Window::loadSettings()
{
	// SETTINGS
	
//	app->loadSettings(settings);
	resize(settings->value("mainwindow/size", QSize(400, 400)).toSize());
	move(settings->value("mainwindow/pos", QPoint(200, 200)).toPoint());
//	tab->setCurrentIndex(settings->value("maintab/index").toInt());
	viewCombo->setCurrentIndex(settings->value("viewCombo/index").toInt());
	restoreState((settings->value("layout/state").toByteArray()));
}

void Window::keyPressEvent(QKeyEvent *event){
	app->keyPressed(event->key());
}

void Window::KeyReleaseEvent(QKeyEvent *event){
	app->keyReleased(event->key());
}

void Window::toggleLock(){
}