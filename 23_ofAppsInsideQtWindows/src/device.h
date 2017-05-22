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
	device(shared_ptr<ofApp> _ofAppPtr, QWidget *parent = Q_NULLPTR);
	~device();
	shared_ptr<ofApp> ofAppPtr;

private:
	Ui::device ui;

//	QThread* somethread;

public slots:
	void on_horizontalSlider_sliderMoved(int value);
//	void newframe();
};
