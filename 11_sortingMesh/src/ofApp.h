#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofxCameraSaveLoad.h"
#include "ofxGifEncoder.h"

class ofApp : public ofBaseApp{
public:
	
	void setup();
	void update();
	void draw();
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	
	void swapA();
	void swapB();
	void swapC();

	void swapVerticesUp();
	void swapVerticesDown();
	void swapNormalsUp();
	void swapNormalsDown();
	void swapIndicesUp();
	void swapIndicesDown();
	
	//model
	ofxAssimpModelLoader model;
	void loadModel();
	ofMesh mesh;
	ofVec3f * vert;
	ofVec3f * norm;
	ofIndexType* index;
	bool drawWire, drawVerts, drawFaces;
	//------

	ofEasyCam cam;
	
	// GIF
	ofxGifEncoder gifEncoder;
	void onGifSaved(string & fileName);
	void exit();
	//------
	
	// dir
	void setupFiles();
	ofDirectory dir;
	unsigned int currentFile;
	
	//lighting
	void setupLighting();
	ofLight pointLight;
	ofColor lightColor;
    float colorHue;
    ofColor materialColor;
	ofMaterial material;
	bool bmoveLight;
	//------

};