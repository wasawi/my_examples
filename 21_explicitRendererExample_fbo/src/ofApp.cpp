#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	window->setVerticalSync(false);
	window->events().setFrameRate(1000);

	camera.setEvents(window->events());
	camera.setRenderer(gl);
	float radius = 200;
	radiusChanged(radius);

	ofDisableArbTex();
	ofFbo::Settings fboSettings(gl);
	fboSettings.width = window->getWidth();
	fboSettings.height = window->getHeight();
	fboSettings.internalformat = GL_RGBA;
	// 	fboSettings.numSamples = 4;
	fullFbo.allocate(fboSettings);
}

void ofApp::radiusChanged(float & radius){
	sphere.set(radius,radius*0.08);
}

GLuint ofApp::getTextureId()
{
	return fullFbo.getTexture().getTextureData().textureID;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	gl->background(255, 255, 255);

	fullFbo.begin();

	gl->background(255, 255, 255);
	// draw sphere
	gl->bind(camera, gl->getCurrentViewport());
	gl->setColor(100, 100 * 0.1);
	gl->draw(sphere, OF_MESH_FILL);
	gl->setColor(0);
	gl->draw(sphere, OF_MESH_WIREFRAME);
	gl->unbind(camera);

	fullFbo.end();

	gl->setColor(255);
	gl->draw(fullFbo.getTexture(), 0, 0, 0, fullFbo.getWidth(), fullFbo.getHeight(), 0, 0, fullFbo.getWidth(), fullFbo.getHeight());


	gl->setColor(0);
	gl->drawString(ofToString(window->events().getFrameRate()),20,20,0);


}

