#ifndef _RENDERERMANAGER_H_
#define _RENDERERMANAGER_H_
#include "IRenderer.h"

class Vector3;

class RendererManager
{
private:
	RendererManager() {};
	~RendererManager() {};
public:
	static RendererManager* Instance()
	{
		static RendererManager instance;
		return &instance;
	}

private:
	IRenderer* renderer;

public:
	void SetRenderer(IRenderer* _renderer);	
	IRenderer* GetRenderer();

	void RendererMgrInit(int argc, char** argv);
	void RendererMgrRenderReset();
	void RendererMgrLoopEvent();
	unsigned int RendererMgrGetMyTextureObject(int _index);
};

#endif 