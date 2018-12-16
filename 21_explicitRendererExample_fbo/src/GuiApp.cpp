#include "GuiApp.h"

#include "teapot.h"

void GuiApp::setup(){

// 	camera.setEvents(window->events());
// 	camera.setRenderer(gl);
// 
 	sphere.set(200, 200 *0.08);
// 	gl->background(255, 255, 255);
// 	mainFont.loadFont("Kroppen Round Regular.otf", 40);


	//ofSetFrameRate(60);
	window->setVerticalSync(false);
	window->events().setFrameRate(1000);
	window->disableSetupScreen();

	// create a texture object
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); // automatic mipmap generation included in OpenGL v1.4
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glBindTexture(GL_TEXTURE_2D, 0);


	//-------------------------------------------------------------------------------

	// create a framebuffer object, you need to delete them when program exits.
	glGenFramebuffers(1, &fboId);
	glBindFramebuffer(GL_FRAMEBUFFER, fboId);

	// attach a texture to FBO color attachement point
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureId, 0);
	//glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureId, 0);

	// create a renderbuffer object to store depth info
	// NOTE: A depth renderable image should be attached the FBO for depth test.
	// If we don't attach a depth renderable image to the FBO, then
	// the rendering output will be corrupted because of missing depth test.
	// If you also need stencil test for your rendering, then you must
	// attach additional image to the stencil attachement point, too.
	glGenRenderbuffers(1, &rboDepthId);
	glBindRenderbuffer(GL_RENDERBUFFER, rboDepthId);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, TEXTURE_WIDTH, TEXTURE_HEIGHT);
	//glRenderbufferStorageMultisample(GL_RENDERBUFFER, fboSampleCount, GL_DEPTH_COMPONENT, TEXTURE_WIDTH, TEXTURE_HEIGHT);
	//	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	// attach a renderbuffer to depth attachment point
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepthId);

	//@@ disable color buffer if you don't attach any color buffer image,
	//@@ for example, rendering the depth buffer only to a texture.
	//@@ Otherwise, glCheckFramebufferStatus will not be complete.
	//glDrawBuffer(GL_NONE);
	//glReadBuffer(GL_NONE);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GuiApp::update(){

}

void GuiApp::draw(){

//	gl->background(255, 255, 255);
//	window->setVerticalSync(false);
////	window->events().setFrameRate(120);
//
//	gl->bind(camera, gl->getCurrentViewport());
//	gl->draw(sphere, OF_MESH_WIREFRAME);
//	gl->setColor(100, 100 * 0.1);
//	gl->draw(sphere, OF_MESH_FILL);
//	gl->unbind(camera);
//
//	gl->setColor(0);
////	gl->drawCircle(100, 100, 0, 50);
////	gl->setBitmapTextMode(OF_BITMAPMODE_SCREEN);
//	gl->drawString(ofToString(window->events().getFrameRate()), 20, 20, 0);


	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	gl->setColor(255);
	gl->setBackgroundColor(100);
	gl->setDepthTest(true);

	// get the total elapsed time
	float playTime = ofGetElapsedTimef();

	// compute rotation angle
	const float ANGLE_SPEED = 20;   // degree/s
	float angle = ANGLE_SPEED * playTime;
	float scale = 100;
	float plane = 1000;

	// set coordinates to top left
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeight, 0, -plane, plane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// draw a rotating teapot at the origin
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glScalef(scale, scale, scale);
	glRotatef(angle*0.5f, 1, 0, 0);
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle*0.7f, 0, 0, 1);
	drawTeapot();
//	gl->draw(sphere, OF_MESH_FILL);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	//-------------------------------------------------------------------------------
	// set rendering destination to FBO
	glBindFramebuffer(GL_FRAMEBUFFER, fboId);

	// clear buffers
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set coordinates to top left
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, 0, windowHeight, -plane, plane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// draw a rotating teapot at the origin
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glPushMatrix();
	glScalef(scale, scale, scale);
	glRotatef(angle*0.5f, 1, 0, 0);
	glRotatef(angle, 0, 1, 0);
	glRotatef(angle*0.7f, 0, 0, 1);
	drawTeapot();
	gl->draw(sphere, OF_MESH_FILL);
	glPopMatrix();
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// unbind FBO
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// trigger mipmaps generation explicitly
	// NOTE: If GL_GENERATE_MIPMAP is set to GL_TRUE, then glCopyTexSubImage2D()
	// triggers mipmap generation automatically. However, the texture attached
	// onto a FBO should generate mipmaps manually via glGenerateMipmap().
	glBindTexture(GL_TEXTURE_2D, textureId);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	//-------------------------------------------------------------------------------

	// set coordinates to top left
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, windowWidth, windowHeight, 0, -plane, plane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gl->setColor(255);
	gl->setBackgroundColor(100);

	glPushMatrix();

	// trigger mipmaps generation explicitly
	glEnable(GL_TEXTURE_2D);

	
	// switch textures
	GLuint texture;
	if (textureReceived) {
		texture = textureR;
	}
	else {
		texture = textureId;
	}

	glBindTexture(GL_TEXTURE_2D, texture);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2i(tx, ty); glVertex2i(x, y);
	glTexCoord2i(tx, th); glVertex2i(x, y + h); // Attention, we first map the lower left corner//
	glTexCoord2i(tw, th); glVertex2i(x + w, y + h);
	glTexCoord2i(tw, ty); glVertex2i(x + w, y);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();

	gl->setColor(0);
	gl->drawString(ofToString(window->events().getFrameRate()), 20, 20, 0);
}

void GuiApp::exit()
{
	//Delete resources
	glDeleteTextures(1, &textureId);
	glDeleteRenderbuffersEXT(1, &rboDepthId);
	//Bind 0, which means render to back buffer, as a result, fb is unbound
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	glDeleteFramebuffersEXT(1, &fboId);
}

void GuiApp::setTextureId(GLuint id)
{
	textureR = id;
}

//--------------------------------------------------------------
void GuiApp::keyPressed(int key) {
	switch (key)
	{
	case ' ':
		textureReceived = !textureReceived;
		break;

	default:
		break;
	}
}

//--------------------------------------------------------------
void GuiApp::keyReleased(int key) {

}