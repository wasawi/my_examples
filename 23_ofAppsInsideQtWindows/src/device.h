#pragma once

#include "ofMain.h"

#include "QtGLWidget.h"
#include "ui_device.h"

#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QThread>

class device : public QWidget
{
	Q_OBJECT

public:
//	device( QWidget *parent = Q_NULLPTR);//shared_ptr<ofApp> _ofAppPtr,
	device(QWidget *parent = Q_NULLPTR, shared_ptr<ofApp> _ofAppPtr = nullptr);//
	~device();

	QHBoxLayout *layout;
	QTimer *timer;
	
//	ofApp ofAppPtr;
	shared_ptr<ofApp> ofAppPtr;
	shared_ptr<ofMainLoop> loop;
	shared_ptr<ofAppQtWindow> mainWindow;

private:
	Ui::device ui;

//	QThread* somethread;

public slots:
	void on_horizontalSlider_sliderMoved(int value);
	void newframe();
};
