#ifndef _OPENGLRENDERER_H_
#define _OPENGLRENDERER_H_

#include "IRenderer.h"
#include <list>
#include <GL/glut.h>
#include <GL/glaux.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/freeglut_std.h>
#pragma comment(lib, "legacy_stdio_definitions.lib")

class OpenGLRenderer : public IRenderer
{
public:
	OpenGLRenderer(){}
	virtual ~OpenGLRenderer();
private:  
	std::list<AUX_RGBImageRec*> texRec;	
	unsigned* MyTextureObject;

public:
	void Init(int argc, char** argv)override;
	void RenderReset()override;
	void LoopEvent()override;

	int LoadGLTextures()override;
	void MakeTextureObjectArr(int _cnt);
	void AddTexture(char* szFilename)override;
	AUX_RGBImageRec* LoadBMP(char* szFilename);
	unsigned int GetMyTextureObject(int _index)override;
};

#endif 