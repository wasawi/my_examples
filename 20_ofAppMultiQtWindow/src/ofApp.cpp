#include "ui_mainwindow.h"
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofLogLevel(OF_LOG_VERBOSE);
	ofLogToConsole();
//	ofSetFrameRate(1);
	ofBackground(0);


//	w = new MainWindow();
//	ui = w->ui;
//	w->show();


    radius = 100;
	color = ofColor::blue;

	//// POPULATE TABLE WITH VECTOR OF STRINGS
 //   vector<string> my_strings;
 //   my_strings.push_back("celery");
 //   my_strings.push_back("pomegranate");
 //   my_strings.push_back("grapefruit");
 //   my_strings.push_back("melon");

 //   int numRows = ui->Table->rowCount();
 //   int numCols = ui->Table->columnCount();
 //   int whichString = 0;

 //   for(int r = 0; r < numRows; r++) {
 //       for(int c = 0; c < numCols; c++) {
 //           QTableWidgetItem *itab = new QTableWidgetItem;
 //           QString qstr = QString::fromStdString(my_strings[whichString]);
 //           itab->setText(qstr);
 //           ui->Table->setItem(r,c,itab);
 //           whichString++;
 //       }
 //   }
	
	cursor = ofPoint(ofGetWindowWidth() / 2 - radius / 2, ofGetWindowHeight() / 2 - radius / 2);
	key_str = "";
}

//--------------------------------------------------------------
void ofApp::setupGui() {

	parameters.setName("parameters");
	parameters.add(radius.set("radius", 50, 1, 100));
	parameters.add(color.set("color", 100, ofColor(0, 0), 255));
	OfGUI.setup(parameters);
}

//--------------------------------------------------------------
void ofApp::drawGui(ofEventArgs & args) {
//	cout << "drawGui" << endl;
	ofBackground(ofColor::black);

//	ofSetBackgroundColor(100);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	ofDisableAlphaBlending();

//	auto renderer = ofGetGLRenderer();
//	renderer->startRender();
	
//	renderer->finishRender();
	ofSetColor(ofColor::white, 100);
	ofRect(ofGetWindowWidth() / 2 - radius / 2, ofGetWindowHeight() / 2 - radius / 2, radius, radius);
	ofSetColor(ofColor::red, 100);
	ofRect(ofGetWindowWidth() / 2 - radius, ofGetWindowHeight() / 2 - radius, radius, radius);

	OfGUI.draw();
}

//--------------------------------------------------------------
void ofApp::update(){
//	cout << "----------------------------" << endl;
    //double xvalue=ui->Slider->value();
    //radius = int(xvalue);

	//if (ui->pushButton->isDown() == true) {
	//	color = ofColor::red;
	//	ofSetWindowPosition(ofGetWindowPositionX() + 10, ofGetWindowPositionY() + 10);
	//	ofSetWindowShape(500, 500);
	//}
	//else {
	//	color = ofColor::white;
	//}

//	cout << ofGetWindowPositionX() << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
//	cout << "draw ofapp" << endl;
	ofBackground(color);

    ofPushStyle();
    ofSetColor(ofColor::ghostWhite);
    ofDrawBitmapStringHighlight("value from slider: " + ofToString(radius), 20, 20);
	ofDrawBitmapString("value from keys: " + key_str, 20, 40);
	key_str = "";
    ofPopStyle();

	//ofSetColor(color);
//    ofEllipse(ofGetWidth()/2, ofGetHeight()/2, radius*2, radius*2);
	ofSetColor(ofColor::black);
	ofRect(ofGetWindowWidth()/2- radius/2, ofGetWindowHeight()/2 - radius / 2, radius, radius);
	ofSetColor(ofColor::yellow, 100);
//	ofSetCircleResolution(20);
	ofCircle(cursor.x, cursor.y, radius / 2);

}

//--------------------------------------------------------------
void ofApp::keyPressed(ofKeyEventArgs& key){
	key_str = key.key;
	cout << key.key <<endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(ofKeyEventArgs&  key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	cursor = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

////--------------------------------------------------------------
//void ofApp::saveSettings(QSettings * settings)
//{
//	controller->saveSettings(settings);
//
//}
////--------------------------------------------------------------
//void ofApp::loadSettings(QSettings * settings)
//{
//	controller->loadSettings(settings);
//
//}