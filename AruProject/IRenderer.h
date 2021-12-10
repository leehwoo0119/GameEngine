#ifndef _IRENDERER_H_
#define _IRENDERER_H_

#include <string>
#include "Vector3.h"

class Camera;

__interface IRenderer
{
public:
	virtual bool Init(int argc, char** argv, int _width, int _height, const char* _title) = 0;
	virtual void RenderReset() = 0;
	virtual void LoopEvent() = 0;

	//�ؽ��� ��������
	virtual int LoadGLTextures() = 0;
	virtual void AddTexture(char* szFilename, std::string _textureName) = 0;
	virtual int GetMyTextureObject(std::string _name) = 0;

	//2D���� ������
	virtual void Render2DCircle(Vector3 _pos, Vector3 _scale) = 0;
	virtual void Render2DTriangle(Vector3 _pos, Vector3 _scale) = 0;
	virtual void Render2DSquare(Vector3 _pos, Vector3 _scale) = 0;

	//2D�ؽ��� ������
	virtual void Render2DTexture(Vector3 _pos, Vector3 _scale, std::string _textureName) = 0;

	//ī�޶�
	virtual void SetCamera(Camera* _camera) = 0;
};

#endif 