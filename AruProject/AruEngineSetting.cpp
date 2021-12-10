#include "AruEngineSetting.h"
#include "RendererManager.h"

AruEngineSetting::AruEngineSetting(const int _width, const int _height, IRenderer* _rendererType, const char* _title)
	:windowWidth(_width), windowHeight(_height), p_RendererType(_rendererType), p_Title(_title)
{
	if (_rendererType)
		RendererManager::Instance()->SetRenderer(_rendererType);
}

int AruEngineSetting::GetWindowWidth()
{
	return windowWidth;
}

int AruEngineSetting::GetWindowHeight()
{
	return windowHeight;
}

const char* AruEngineSetting::GetTitle()
{
	return p_Title;
}

