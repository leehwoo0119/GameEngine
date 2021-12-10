#ifndef _OPENGLRENDERER_H_
#define _OPENGLRENDERER_H_

#include "IRenderer.h"
#include <list>
#include <map>
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
	OpenGLRenderer();
	virtual ~OpenGLRenderer();

private:  
	std::list<AUX_RGBImageRec*> m_TexRec;	
	std::map<std::string, int> m_TextureInfo;
	unsigned* p_MyTextureObject;
	Camera* p_Camera;
	int textureNum;

public:
	bool Init(int argc, char** argv, int _width, int _height, const char* _title)override;
	void RenderReset()override;
	void LoopEvent()override;

	int LoadGLTextures()override;
	void AddTexture(char* szFilename, std::string _textureName)override;
	int GetMyTextureObject(std::string _name)override;

	void Render2DCircle(Vector3 _pos, Vector3 _scale) override;
	void Render2DTriangle(Vector3 _pos, Vector3 _scale)override;
	void Render2DSquare(Vector3 _pos, Vector3 _scale) override;

	void Render2DTexture(Vector3 _pos, Vector3 _scale, std::string _textureName)override;

	void SetCamera(Camera* _camera)override;

private:
	static void ResetDisplay();
	static void DisplayCamera();
	void MakeTextureObjectArr(int _cnt);
	AUX_RGBImageRec* LoadBMP(char* szFilename);
};

#endif 