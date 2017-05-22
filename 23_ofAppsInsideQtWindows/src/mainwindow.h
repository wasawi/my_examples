#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ofMain.h"

#include <vector>
#include <QMainWindow>
#include <QMdiSubWindow>
#include <QWidget>



namespace Ui {
class MainWindow;
}

class ofApp;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	shared_ptr<ofApp> ofAppPtr;

public slots:
	void on_actionIMX262_triggered();

private:
	Ui::MainWindow *ui;
	void loadSubWindow(QWidget* widget);

	// the OF App

};

/*
private:
    Ui::MainWindow *ui;
};*/

#endif // MAINWINDOW_H
