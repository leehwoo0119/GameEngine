#ifndef _ARUENGINEMANAGER_H_
#define _ARUENGINEMANAGER_H_

#include "IRenderer.h"

class AruEngineSetting
{
public:
	AruEngineSetting(const int _width, const int _height, IRenderer* _rendererType, const char* _title);
	~AruEngineSetting() {}

private:
	int windowWidth;
	int windowHeight;
	const char* p_Title;
	IRenderer* p_RendererType;

public:
	int GetWindowWidth();
	int GetWindowHeight();
	const char* GetTitle();
;};

#endif 