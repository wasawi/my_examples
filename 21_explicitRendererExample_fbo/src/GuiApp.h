#pragma once

#include "ofMain.h"
#include "ofxGui.h"


#define windowWidth 800
#define windowHeight 600

#define TEXTURE_WIDTH 300
#define TEXTURE_HEIGHT 300

class GuiApp: public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void exit();
	void keyPressed(int key);
	void keyReleased(int key);

	bool textureReceived = false;
	void setTextureId(GLuint id);

	shared_ptr<ofAppBaseWindow> window;
	shared_ptr<ofBaseGLRenderer> gl;
	ofSpherePrimitive sphere;
//	ofTrueTypeFont mainFont;
//	ofEasyCam camera;

	bool fboSupported;
	bool fboUsed;
	GLuint textureId, fboId, rboDepthId;
	GLuint textureR;

	int tx = 0;
	int ty = 0;
	int tw = 1;
	int th = 1;

	int x = 200;
	int y = 100;
	int w = 300;
	int h = 300;
};

