#include "mainwindow.h"
#include "ofMain.h"
#include "ofApp.h"
#include <QApplication>

int main( )
{
    ofSetupOpenGL(400, 200, OF_WINDOW);

    int argc = 0;
    char *argv[] = {0};
    QApplication a(argc, argv);
    MainWindow w;

    ofApp* app = new ofApp();
    app->ui = w.ui;

    w.show();
    //a.exec(); < this doesn't work for some reason
    ofRunApp( app );
}
