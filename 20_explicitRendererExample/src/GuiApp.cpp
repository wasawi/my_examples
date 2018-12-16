/*
 * GuiApp.cpp
 *
 *  Created on: Oct 28, 2014
 *      Author: arturo
 */

#include "GuiApp.h"

void GuiApp::setup(){
//	parameters.setName("parameters");
//	parameters.add(radius.set("radius",280,20,400));
//	parameters.add(color.set("color",100,ofColor(0,0),255));
//	gui.setup(parameters);
//	ofBackground(0);
//	ofSetVerticalSync(false);

	camera.setEvents(window->events());
	camera.setRenderer(gl);

	sphere.set(200, 200 *0.08);
	gl->background(255, 255, 255);
	mainFont.loadFont("Kroppen Round Regular.otf", 40);
}

void GuiApp::update(){

}

void GuiApp::draw(){

	gl->background(255, 255, 255);
	window->setVerticalSync(false);
//	window->events().setFrameRate(120);

	gl->bind(camera, gl->getCurrentViewport());
	gl->draw(sphere, OF_MESH_WIREFRAME);
	gl->setColor(100, 100 * 0.1);
	gl->draw(sphere, OF_MESH_FILL);
	gl->unbind(camera);

	gl->setColor(0);
//	gl->drawCircle(100, 100, 0, 50);
//	gl->setBitmapTextMode(OF_BITMAPMODE_SCREEN);
	gl->drawString(ofToString(window->events().getFrameRate()), 20, 20, 0);
}
