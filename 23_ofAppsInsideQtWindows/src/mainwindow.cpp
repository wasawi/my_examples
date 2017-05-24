#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "device.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


	ofAppPtr = make_shared<ofApp>();
//	shared_ptr<ofApp> ofAppPtr(new ofApp);

//	connect(ui->actionIMX262, SIGNAL(triggered()), this, SLOT(openWindow()));
}

//void MainWindow::openWindow()
//{
//	ui->mdiArea->addSubWindow(ui->IMX262);
//	ui->IMX262->show();
//}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionIMX262_triggered() {
//	ofAppPtr = make_shared<ofApp>();
//	loadSubWindow(new device( ofAppPtr, this));
	loadSubWindow(new device(this, ofAppPtr));
//	loadSubWindow(new device(this));

}

void MainWindow::loadSubWindow(QWidget* widget) {
	auto window = ui->mdiArea->addSubWindow(widget);
	window->setWindowTitle(widget->windowTitle());
	window->setWindowIcon(widget->windowIcon());
	window->show();
}