#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};


/*
http://forum.openframeworks.cc/t/getting-absolute-value-of-a-transformed-point-coordinate/4633/19
 
 The difference being, not hard to guess, the multiplication order of these matrix operations.
 
 If you want to apply and combine your matrices like you did using the openGL matrix stack, I'd recommend using the ofMatrix.gl(*) - versions of the transform methods.
 
 ofMatrix4x4 m;
 m.glTranslate(20,0,0);
 m.glRotate(90,0,0,1);
 ofVec3f v(0,0,0);
 v = v * m;
 will first rotate your point 90 degrees, then move it 20 units to the right (leading to: x=20, y=0), whereas
 
 ofMatrix4x4 m;
 m.translate(20,0,0);
 m.rotate(90,0,0,1);
 ofVec3f v(0,0,0);
 v = v * m;
 will first translate your point 20 units to the right and then rotate the coordinate system 90 degrees, leading to x = 0, y= 20.
 
 ***
 
 So, the short answer is:
 
 reverse your vector-matrix multiplication order
 use ofMatrix::glTranslate(), ofMatrix::glScale() etc instead of ofMatrix()::translate, ofMatrix()::scale of you want to combine transformations like you are used to from OpenGL
 ***

*/