#include "RendererManager.h"
#include "Vector3.h"
#include "Camera.h"
#include <assert.h>

void RendererManager::SetRenderer(IRenderer* _renderer)
{
	p_Renderer = _renderer;
}

IRenderer* RendererManager::GetRenderer()
{
	assert(p_Renderer != NULL);
	return p_Renderer;
}

bool RendererManager::RendererMgrInit(int argc, char** argv, AruEngineSetting _setting)
{
	assert(p_Renderer != NULL);
	return (p_Renderer->Init(argc, argv, _setting.GetWindowWidth(),
		_setting.GetWindowHeight(),
		_setting.GetTitle()));
}

void RendererManager::RendererMgrLoopEvent()
{
	assert(p_Renderer != NULL);
	p_Renderer->RenderReset();
	p_Renderer->LoopEvent();
}

void RendererManager::SetCamera(Camera* _camera)
{
	assert(p_Renderer != NULL);
	p_Camera = _camera;
	if (!p_Camera)
		p_Renderer->SetCamera(p_Camera);
}

Vector3 RendererManager::GetCameraPos()
{
	if(p_Camera)
		return p_Camera->GetCameraPosition();
	return Vector3(0, 0, 0);
}


