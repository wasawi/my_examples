#pragma once

#include "ofMain.h"
#include "GuiApp.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void radiusChanged(float & radius);

		GLuint getTextureId();
		
		shared_ptr<ofAppBaseWindow> window;
		shared_ptr<ofBaseGLRenderer> gl;
		ofSpherePrimitive sphere;
		ofEasyCam camera;

		ofFbo fullFbo;
};
