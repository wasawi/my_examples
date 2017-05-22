#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <QMdiSubWindow>
#include <QWidget>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void on_actionIMX262_triggered();
private:
	Ui::MainWindow *ui;
	void loadSubWindow(QWidget* widget);

	// the OF App
//	shared_ptr<ofApp> mainApp;
};

/*
private:
    Ui::MainWindow *ui;
};*/

#endif // MAINWINDOW_H
