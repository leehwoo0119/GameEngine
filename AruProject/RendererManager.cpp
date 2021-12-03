#include "RendererManager.h"
#include "Vector3.h"

void RendererManager::SetRenderer(IRenderer* _renderer)
{
	renderer = _renderer;
}

IRenderer* RendererManager::GetRenderer()
{
	return renderer;
}

void RendererManager::RendererMgrInit(int argc, char** argv)
{
	if(renderer)
		renderer->Init(argc, argv);
}

void RendererManager::RendererMgrRenderReset()
{
	if (renderer)
		renderer->RenderReset();
}

void RendererManager::RendererMgrLoopEvent()
{
	if (renderer)
		renderer->LoopEvent();
}

unsigned int RendererManager::RendererMgrGetMyTextureObject(int _index)
{
	if (renderer)
		return renderer->GetMyTextureObject(_index);
	else
		return false;
}

