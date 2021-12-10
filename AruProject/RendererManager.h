#ifndef _RENDERERMANAGER_H_
#define _RENDERERMANAGER_H_ 
#include "IRenderer.h"
#include "AruEngineSetting.h"

class Vector3;
class Camera;

class RendererManager
{
private:
	RendererManager() :p_Renderer(nullptr), p_Camera(nullptr) {}
	~RendererManager() {}

public:
	static RendererManager* Instance()
	{
		static RendererManager instance;
		return &instance;
	}

private:
	IRenderer* p_Renderer;
	Camera* p_Camera;

public:
	void SetRenderer(IRenderer* _renderer);	
	IRenderer* GetRenderer();

	bool RendererMgrInit(int argc, char** argv, AruEngineSetting _setting);
	void RendererMgrLoopEvent();

	void SetCamera(Camera* _camera);
	Vector3 GetCameraPos();
};

#endif 