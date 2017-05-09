
#include "ofMain.h"
#include <QtGui>
#include <QtOpenGL>
#include <QtGlobal>

#include <math.h>

#include "glwidget.h"

//
//GLWidget::GLWidget(shared_ptr<ofBaseApp> app, QWidget *parent): QGLWidget(parent)
//{
//	qt_set_sequence_auto_mnemonic(true);
//	ofApp = app;
//	drawMethod = (&ofApp::draw);
//	frameRate = 0;
//	frames = 0;
//	mousePressed = 0;	
//	setMouseTracking(true);
//	makeCurrent();
//	
//}

GLWidget::~GLWidget()
{
    makeCurrent();
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 400);
}

void GLWidget::setXRotation(int angle)
{
//	((ofApp*)ofApp)->slider1 = angle;
	
}
void GLWidget::setRotateSlider(int angle)
{
//	((ofApp*)ofApp)->rotateSlider = angle;	
}

void GLWidget::initializeGL()
{	
}

void GLWidget::update(){
	static ofEventArgs voidEventArgs;
	ofApp->update();
#ifdef OF_USING_POCO
	ofNotifyEvent( ofEvents.update, voidEventArgs );
#endif
}

void GLWidget::paintGL()
{
	makeCurrent();
	static ofEventArgs voidEventArgs;
	
	//Update framerate
	frameRate = frames /(time.elapsed() / 1000.0);
	frameRateChanged(frameRate);
	if (!(frames % 100)) {
		time.start();
		frames = 0;
	}
	frames ++;
	
	//Draw
	glPushMatrix();
	if(ofbClearBg()){
		glClearColor(ofGetBackgroundColor()[0], ofGetBackgroundColor()[1], ofGetBackgroundColor()[2], ofGetBackgroundColor()[3]);
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	

	ofApp->draw(viewCombo->currentIndex());
	//(ofApp->*drawMethod)();
#ifdef OF_USING_POCO
	ofNotifyEvent( ofEvents.draw, voidEventArgs );
#endif
	
	glPopMatrix();
}

void GLWidget::resizeGL(int width, int height)
{
	ofApp->windowResized(width, height);
	
	glViewport(0, 0, width, height);
	ofSetupScreen();			
	glFlush();
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
	lastPos = event->pos();
	mousePressed = event->button();
	static ofMouseEventArgs mouseEventArgs;
	mouseEventArgs.x = event->pos().x();
	mouseEventArgs.y = event->pos().y();
	mouseEventArgs.button = mousePressed;
	ofApp->mousePressed(event->pos().x(), event->pos().y(), event->button());
#ifdef OF_USING_POCO
	ofNotifyEvent( ofEvents.mousePressed, mouseEventArgs );
#endif
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
	lastPos = event->pos();
	mousePressed = 0;

	static ofMouseEventArgs mouseEventArgs;
	mouseEventArgs.x = event->pos().x();
	mouseEventArgs.y = event->pos().y();
	mouseEventArgs.button = mousePressed;
	ofApp->mouseReleased(event->pos().x(), event->pos().y(), event->button());
#ifdef OF_USING_POCO
	ofNotifyEvent( ofEvents.mouseReleased, mouseEventArgs );
#endif
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
	static ofMouseEventArgs mouseEventArgs;
	mouseEventArgs.x = event->pos().x();
	mouseEventArgs.y = event->pos().y();
	mouseEventArgs.button = mousePressed;

	ofApp->mouseX = event->pos().x();
	ofApp->mouseY = event->pos().y();
	if(mousePressed == 0){
		ofApp->mouseMoved(event->pos().x(), event->pos().y());
#ifdef OF_USING_POCO
		ofNotifyEvent( ofEvents.mouseMoved, mouseEventArgs );
#endif
	} else {
		ofApp->mouseDragged(event->pos().x(), event->pos().y(), mousePressed);
#ifdef OF_USING_POCO
		ofNotifyEvent( ofEvents.mouseDragged, mouseEventArgs );
#endif
	}
	lastPos = event->pos();
}


