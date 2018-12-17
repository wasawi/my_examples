#include "Simple_fbo.h"
#include "glinfo.h"

//--------------------------------------------------------------
void Simple_fbo::setup(int _x, int _y, int _width, int _height){
	x = _x;
	y = _y;
	fbo_width = _width;
	fbo_height = _height;
//	windowWidth = fbo_width;
//	windowHeight = fbo_height;

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
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, fbo_width, fbo_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
	glBindTexture(GL_TEXTURE_2D, 0);

	//-------------------------------------------------------------------------------

	// get OpenGL info
	glInfo glInfo;
	glInfo.getInfo();
	glInfo.printSelf();

	// check if FBO is supported by your video card
	if (glInfo.isExtensionSupported("GL_ARB_framebuffer_object"))
	{
		// get pointers to GL functions
		glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)wglGetProcAddress("glGenFramebuffers");
		glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)wglGetProcAddress("glDeleteFramebuffers");
		glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)wglGetProcAddress("glBindFramebuffer");
		glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)wglGetProcAddress("glCheckFramebufferStatus");
		glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)wglGetProcAddress("glGetFramebufferAttachmentParameteriv");
		glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
		glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)wglGetProcAddress("glFramebufferTexture1D");
		glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)wglGetProcAddress("glFramebufferTexture2D");
		glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)wglGetProcAddress("glFramebufferTexture3D");
		glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)wglGetProcAddress("glFramebufferTextureLayer");
		glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)wglGetProcAddress("glFramebufferRenderbuffer");
		glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)wglGetProcAddress("glIsFramebuffer");
		glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)wglGetProcAddress("glBlitFramebuffer");
		glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)wglGetProcAddress("glGenRenderbuffers");
		glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)wglGetProcAddress("glDeleteRenderbuffers");
		glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)wglGetProcAddress("glBindRenderbuffer");
		glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)wglGetProcAddress("glRenderbufferStorage");
		glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)wglGetProcAddress("glRenderbufferStorageMultisample");
		glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)wglGetProcAddress("glGetRenderbufferParameteriv");
		glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)wglGetProcAddress("glIsRenderbuffer");

		// check once again FBO extension
		if (glGenFramebuffers && glDeleteFramebuffers && glBindFramebuffer && glCheckFramebufferStatus &&
			glGetFramebufferAttachmentParameteriv && glGenerateMipmap && glFramebufferTexture1D && glFramebufferTexture2D && glFramebufferTexture3D &&
			glFramebufferTextureLayer && glFramebufferRenderbuffer && glIsFramebuffer && glBlitFramebuffer &&
			glGenRenderbuffers && glDeleteRenderbuffers && glBindRenderbuffer && glRenderbufferStorage &&
			glRenderbufferStorageMultisample && glGetRenderbufferParameteriv && glIsRenderbuffer)
		{
			fboSupported = fboUsed = true;
			std::cout << "Video card supports GL_ARB_framebuffer_object." << std::endl;
		}
		else
		{
			fboSupported = fboUsed = false;
			std::cout << "Video card does NOT support GL_ARB_framebuffer_object." << std::endl;
		}
	}

	// check EXT_swap_control is supported
	if (glInfo.isExtensionSupported("WGL_EXT_swap_control"))
	{
		// get pointers to WGL functions
		wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
		if (wglSwapIntervalEXT && wglGetSwapIntervalEXT)
		{
			// disable v-sync
			wglSwapIntervalEXT(0);
			std::cout << "Video card supports WGL_EXT_swap_control." << std::endl;
		}
	}

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
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, fbo_width, fbo_height);
	//glRenderbufferStorageMultisample(GL_RENDERBUFFER, fboSampleCount, GL_DEPTH_COMPONENT, TEXTURE_WIDTH, TEXTURE_HEIGHT);
	//	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	// attach a renderbuffer to depth attachment point
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepthId);

	//@@ disable color buffer if you don't attach any color buffer image,
	//@@ for example, rendering the depth buffer only to a texture.
	//@@ Otherwise, glCheckFramebufferStatus will not be complete.
	//glDrawBuffer(GL_NONE);
	//glReadBuffer(GL_NONE);

	// check FBO status
	printFramebufferInfo(fboId);
	bool status = checkFramebufferStatus(fboId);
	if (!status) {
		std::cout << "ERROR" << std::endl;
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

//-------------------------------------------------------------------------------
void Simple_fbo::begin()
{
	// set rendering destination to FBO
	glBindFramebuffer(GL_FRAMEBUFFER, fboId);

	// clear buffers
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0);

	glPushMatrix();

	// set coordinates to top left of the fbo
	glViewport(0, 0, fbo_width, fbo_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, fbo_width, 0, fbo_height, -plane, plane);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//-------------------------------------------------------------------------------
void Simple_fbo::end()
{

	glPopMatrix();

	// unbind FBO
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// trigger mipmaps generation explicitly
	// NOTE: If GL_GENERATE_MIPMAP is set to GL_TRUE, then glCopyTexSubImage2D()
	// triggers mipmap generation automatically. However, the texture attached
	// onto a FBO should generate mipmaps manually via glGenerateMipmap().
	glBindTexture(GL_TEXTURE_2D, textureId);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	//// set coordinates to top left
	//glViewport(0, 0, windowWidth, windowHeight);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0, windowWidth, 0, windowHeight, -plane, plane);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
}

//-------------------------------------------------------------------------------
void Simple_fbo::draw() {

	//// set coordinates to top left
	//glViewport(0, 0, windowWidth, windowHeight);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0, windowWidth, windowHeight, 0, -plane, plane);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	glColor4f(1.0f, 1.0f, 1.0f, 1.0);

	w = fbo_width;
	h = fbo_height;

	// draw texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2i(tx, ty); glVertex2i(x, y);
	glTexCoord2i(tx, th); glVertex2i(x, y + h); // Attention, we first map the lower left corner//
	glTexCoord2i(tw, th); glVertex2i(x + w, y + h);
	glTexCoord2i(tw, ty); glVertex2i(x + w, y);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}


void Simple_fbo::destroy()
{
	//Delete resources
	glDeleteTextures(1, &textureId);
	glDeleteRenderbuffersEXT(1, &rboDepthId);
	//Bind 0, which means render to back buffer, as a result, fb is unbound
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
	glDeleteFramebuffersEXT(1, &fboId);
}

void Simple_fbo::printFramebufferInfo(GLuint fbo)
{
	// bind fbo
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	std::cout << "\n===== FBO STATUS =====\n";

	// print max # of colorbuffers supported by FBO
	int colorBufferCount = 0;
	glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &colorBufferCount);
	std::cout << "Max Number of Color Buffer Attachment Points: " << colorBufferCount << std::endl;

	// get max # of multi samples
	int multiSampleCount = 0;
	glGetIntegerv(GL_MAX_SAMPLES, &multiSampleCount);
	std::cout << "Max Number of Samples for MSAA: " << multiSampleCount << std::endl;

	int objectType;
	int objectId;

	// print info of the colorbuffer attachable image
	for (int i = 0; i < colorBufferCount; ++i)
	{
		glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER,
			GL_COLOR_ATTACHMENT0 + i,
			GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,
			&objectType);
		if (objectType != GL_NONE)
		{
			glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER,
				GL_COLOR_ATTACHMENT0 + i,
				GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,
				&objectId);

			std::string formatName;

			std::cout << "Color Attachment " << i << ": ";
			if (objectType == GL_TEXTURE)
			{
				std::cout << "GL_TEXTURE, " << getTextureParameters(objectId) << std::endl;
			}
			else if (objectType == GL_RENDERBUFFER)
			{
				std::cout << "GL_RENDERBUFFER, " << getRenderbufferParameters(objectId) << std::endl;
			}
		}
	}

	// print info of the depthbuffer attachable image
	glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER,
		GL_DEPTH_ATTACHMENT,
		GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,
		&objectType);
	if (objectType != GL_NONE)
	{
		glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER,
			GL_DEPTH_ATTACHMENT,
			GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,
			&objectId);

		std::cout << "Depth Attachment: ";
		switch (objectType)
		{
		case GL_TEXTURE:
			std::cout << "GL_TEXTURE, " << getTextureParameters(objectId) << std::endl;
			break;
		case GL_RENDERBUFFER:
			std::cout << "GL_RENDERBUFFER, " << getRenderbufferParameters(objectId) << std::endl;
			break;
		}
	}

	// print info of the stencilbuffer attachable image
	glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER,
		GL_STENCIL_ATTACHMENT,
		GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,
		&objectType);
	if (objectType != GL_NONE)
	{
		glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER,
			GL_STENCIL_ATTACHMENT,
			GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,
			&objectId);

		std::cout << "Stencil Attachment: ";
		switch (objectType)
		{
		case GL_TEXTURE:
			std::cout << "GL_TEXTURE, " << getTextureParameters(objectId) << std::endl;
			break;
		case GL_RENDERBUFFER:
			std::cout << "GL_RENDERBUFFER, " << getRenderbufferParameters(objectId) << std::endl;
			break;
		}
	}

	std::cout << std::endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

bool Simple_fbo::checkFramebufferStatus(GLuint fbo)
{
	// check FBO status
	glBindFramebuffer(GL_FRAMEBUFFER, fbo); // bind
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	switch (status)
	{
	case GL_FRAMEBUFFER_COMPLETE:
		std::cout << "Framebuffer complete." << std::endl;
		return true;

	case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
		std::cout << "[ERROR] Framebuffer incomplete: Attachment is NOT complete." << std::endl;
		return false;

	case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
		std::cout << "[ERROR] Framebuffer incomplete: No image is attached to FBO." << std::endl;
		return false;
		/*
		case GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS:
		std::cout << "[ERROR] Framebuffer incomplete: Attached images have different dimensions." << std::endl;
		return false;

		case GL_FRAMEBUFFER_INCOMPLETE_FORMATS:
		std::cout << "[ERROR] Framebuffer incomplete: Color attached images have different internal formats." << std::endl;
		return false;
		*/
	case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
		std::cout << "[ERROR] Framebuffer incomplete: Draw buffer." << std::endl;
		return false;

	case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
		std::cout << "[ERROR] Framebuffer incomplete: Read buffer." << std::endl;
		return false;

	case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
		std::cout << "[ERROR] Framebuffer incomplete: Multisample." << std::endl;
		return false;

	case GL_FRAMEBUFFER_UNSUPPORTED:
		std::cout << "[ERROR] Framebuffer incomplete: Unsupported by FBO implementation." << std::endl;
		return false;

	default:
		std::cout << "[ERROR] Framebuffer incomplete: Unknown error." << std::endl;
		return false;
	}
	glBindFramebuffer(GL_FRAMEBUFFER, 0);   // unbind
}

std::string Simple_fbo::getTextureParameters(GLuint id)
{
	if (glIsTexture(id) == GL_FALSE)
		return "Not texture object";

	int width, height, format;
	std::string formatName;
	glBindTexture(GL_TEXTURE_2D, id);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &width);            // get texture width
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &height);          // get texture height
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &format); // get texture internal format
	glBindTexture(GL_TEXTURE_2D, 0);

	formatName = convertInternalFormatToString(format);

	std::stringstream ss;
	ss << width << "x" << height << ", " << formatName;
	return ss.str();
}

std::string Simple_fbo::getRenderbufferParameters(GLuint id)
{
	if (glIsRenderbuffer(id) == GL_FALSE)
		return "Not Renderbuffer object";

	int width, height, format, samples;
	std::string formatName;
	glBindRenderbuffer(GL_RENDERBUFFER, id);
	glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &width);       // get renderbuffer width
	glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &height);     // get renderbuffer height
	glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &format); // get renderbuffer internal format
	glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_SAMPLES, &samples);   // get multisample count
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	formatName = convertInternalFormatToString(format);

	std::stringstream ss;
	ss << width << "x" << height << ", " << formatName << ", MSAA(" << samples << ")";
	return ss.str();
}

std::string Simple_fbo::convertInternalFormatToString(GLenum format)
{
	std::string formatName;

	switch (format)
	{
	case GL_STENCIL_INDEX:      // 0x1901
		formatName = "GL_STENCIL_INDEX";
		break;
	case GL_DEPTH_COMPONENT:    // 0x1902
		formatName = "GL_DEPTH_COMPONENT";
		break;
	case GL_ALPHA:              // 0x1906
		formatName = "GL_ALPHA";
		break;
	case GL_RGB:                // 0x1907
		formatName = "GL_RGB";
		break;
	case GL_RGBA:               // 0x1908
		formatName = "GL_RGBA";
		break;
	case GL_LUMINANCE:          // 0x1909
		formatName = "GL_LUMINANCE";
		break;
	case GL_LUMINANCE_ALPHA:    // 0x190A
		formatName = "GL_LUMINANCE_ALPHA";
		break;
	case GL_R3_G3_B2:           // 0x2A10
		formatName = "GL_R3_G3_B2";
		break;
	case GL_ALPHA4:             // 0x803B
		formatName = "GL_ALPHA4";
		break;
	case GL_ALPHA8:             // 0x803C
		formatName = "GL_ALPHA8";
		break;
	case GL_ALPHA12:            // 0x803D
		formatName = "GL_ALPHA12";
		break;
	case GL_ALPHA16:            // 0x803E
		formatName = "GL_ALPHA16";
		break;
	case GL_LUMINANCE4:         // 0x803F
		formatName = "GL_LUMINANCE4";
		break;
	case GL_LUMINANCE8:         // 0x8040
		formatName = "GL_LUMINANCE8";
		break;
	case GL_LUMINANCE12:        // 0x8041
		formatName = "GL_LUMINANCE12";
		break;
	case GL_LUMINANCE16:        // 0x8042
		formatName = "GL_LUMINANCE16";
		break;
	case GL_LUMINANCE4_ALPHA4:  // 0x8043
		formatName = "GL_LUMINANCE4_ALPHA4";
		break;
	case GL_LUMINANCE6_ALPHA2:  // 0x8044
		formatName = "GL_LUMINANCE6_ALPHA2";
		break;
	case GL_LUMINANCE8_ALPHA8:  // 0x8045
		formatName = "GL_LUMINANCE8_ALPHA8";
		break;
	case GL_LUMINANCE12_ALPHA4: // 0x8046
		formatName = "GL_LUMINANCE12_ALPHA4";
		break;
	case GL_LUMINANCE12_ALPHA12:// 0x8047
		formatName = "GL_LUMINANCE12_ALPHA12";
		break;
	case GL_LUMINANCE16_ALPHA16:// 0x8048
		formatName = "GL_LUMINANCE16_ALPHA16";
		break;
	case GL_INTENSITY:          // 0x8049
		formatName = "GL_INTENSITY";
		break;
	case GL_INTENSITY4:         // 0x804A
		formatName = "GL_INTENSITY4";
		break;
	case GL_INTENSITY8:         // 0x804B
		formatName = "GL_INTENSITY8";
		break;
	case GL_INTENSITY12:        // 0x804C
		formatName = "GL_INTENSITY12";
		break;
	case GL_INTENSITY16:        // 0x804D
		formatName = "GL_INTENSITY16";
		break;
	case GL_RGB4:               // 0x804F
		formatName = "GL_RGB4";
		break;
	case GL_RGB5:               // 0x8050
		formatName = "GL_RGB5";
		break;
	case GL_RGB8:               // 0x8051
		formatName = "GL_RGB8";
		break;
	case GL_RGB10:              // 0x8052
		formatName = "GL_RGB10";
		break;
	case GL_RGB12:              // 0x8053
		formatName = "GL_RGB12";
		break;
	case GL_RGB16:              // 0x8054
		formatName = "GL_RGB16";
		break;
	case GL_RGBA2:              // 0x8055
		formatName = "GL_RGBA2";
		break;
	case GL_RGBA4:              // 0x8056
		formatName = "GL_RGBA4";
		break;
	case GL_RGB5_A1:            // 0x8057
		formatName = "GL_RGB5_A1";
		break;
	case GL_RGBA8:              // 0x8058
		formatName = "GL_RGBA8";
		break;
	case GL_RGB10_A2:           // 0x8059
		formatName = "GL_RGB10_A2";
		break;
	case GL_RGBA12:             // 0x805A
		formatName = "GL_RGBA12";
		break;
	case GL_RGBA16:             // 0x805B
		formatName = "GL_RGBA16";
		break;
	case GL_DEPTH_COMPONENT16:  // 0x81A5
		formatName = "GL_DEPTH_COMPONENT16";
		break;
	case GL_DEPTH_COMPONENT24:  // 0x81A6
		formatName = "GL_DEPTH_COMPONENT24";
		break;
	case GL_DEPTH_COMPONENT32:  // 0x81A7
		formatName = "GL_DEPTH_COMPONENT32";
		break;
	case GL_DEPTH_STENCIL:      // 0x84F9
		formatName = "GL_DEPTH_STENCIL";
		break;
	case GL_RGBA32F:            // 0x8814
		formatName = "GL_RGBA32F";
		break;
	case GL_RGB32F:             // 0x8815
		formatName = "GL_RGB32F";
		break;
	case GL_RGBA16F:            // 0x881A
		formatName = "GL_RGBA16F";
		break;
	case GL_RGB16F:             // 0x881B
		formatName = "GL_RGB16F";
		break;
	case GL_DEPTH24_STENCIL8:   // 0x88F0
		formatName = "GL_DEPTH24_STENCIL8";
		break;
	default:
		std::stringstream ss;
		ss << "Unknown Format(0x" << std::hex << format << ")" << std::ends;
		formatName = ss.str();
	}

	return formatName;
}