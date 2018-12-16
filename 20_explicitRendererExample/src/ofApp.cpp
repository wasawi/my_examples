#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	camera.setEvents(window->events());
	camera.setRenderer(gl);
	float radius = 200;
	radiusChanged(radius);
}

void ofApp::radiusChanged(float & radius){
	sphere.set(radius,radius*0.08);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	gl->background(255, 255, 255);
	window->setVerticalSync(true);

//	window->setVerticalSync(false);
//	window->events().setFrameRate(120);

	gl->bind(camera,gl->getCurrentViewport());
//	gl->setColor(gui->color);
	gl->draw(sphere,OF_MESH_WIREFRAME);
//	gl->setColor(gui->color,gui->color->a*0.1);
	gl->setColor(100,100*0.1);
	gl->draw(sphere,OF_MESH_FILL);
	gl->unbind(camera);

	gl->setColor(0);
	gl->drawString(ofToString(window->events().getFrameRate()),20,20,0);
}

