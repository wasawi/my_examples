#pragma once

#include "QtGLWidget.h"
#include "ui_device.h"
#include <QWidget>
#include <QOpenGLWidget>
#include <QHBoxLayout>
#include <QTimer>

class device : public QWidget
{
	Q_OBJECT

public:
	device(QWidget *parent = Q_NULLPTR);
	~device();

private:
	Ui::device ui;
	shared_ptr<ofApp> mainApp;
};
