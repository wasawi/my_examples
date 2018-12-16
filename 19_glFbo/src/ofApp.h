#pragma once

#include "ofMain.h"


#define windowWidth 800
#define windowHeight 600

#define TEXTURE_WIDTH 300
#define TEXTURE_HEIGHT 300

class ofApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		

        // member variables to store the current mouse X and Y position 
        // as a percentage of the width/height of the screen
        float mouseXPercent, mouseYPercent;

		int width = 300;
		int height = 300;


		bool fboSupported;
		bool fboUsed;
		GLuint textureId, fboId, rboDepthId;
		int tx = 0;
		int ty = 0;
		int tw = 1;
		int th = 1;

		int x = 200;
		int y = 100;
		int w = 300;
		int h = 300;

		const float CAMERA_DISTANCE = 6.0f;

		///////////////////////////////////////////////////////////////////////////////
		// print out the FBO infos
		///////////////////////////////////////////////////////////////////////////////
		void printFramebufferInfo(GLuint fbo);


		///////////////////////////////////////////////////////////////////////////////
		// check FBO completeness
		///////////////////////////////////////////////////////////////////////////////
		bool checkFramebufferStatus(GLuint fbo);


		///////////////////////////////////////////////////////////////////////////////
		// return texture parameters as string using glGetTexLevelParameteriv()
		///////////////////////////////////////////////////////////////////////////////
		std::string getTextureParameters(GLuint id);



		///////////////////////////////////////////////////////////////////////////////
		// return renderbuffer parameters as string using glGetRenderbufferParameteriv
		///////////////////////////////////////////////////////////////////////////////
		std::string getRenderbufferParameters(GLuint id);

		///////////////////////////////////////////////////////////////////////////////
		// convert OpenGL internal format enum to string
		///////////////////////////////////////////////////////////////////////////////
		std::string convertInternalFormatToString(GLenum format);
};
	
