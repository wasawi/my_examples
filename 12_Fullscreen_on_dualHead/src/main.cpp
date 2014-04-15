
#if !defined GLFWWINDOW
#include "ofMain.h"
#include "ofApp.h"
int main( ){
//	ofAppBaseWindow window;
	ofSetupOpenGL(1360,768,OF_FULLSCREEN);

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());
}
#endif


#if defined GLFWWINDOW
#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"
int main(){
	ofAppGLFWWindow window;
	window.setMultiDisplayFullscreen(true);
	ofSetupOpenGL(&window, 1360, 768*2, OF_FULLSCREEN);
	ofRunApp(new ofApp());
}
#endif
