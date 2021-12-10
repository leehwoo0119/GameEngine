#ifndef _RENDER2DTEXTURE_H_
#define _RENDER2DTEXTURE_H_
#include "Component.h"

class Render2DTexture : public Component
{
public:
	Render2DTexture(std::string _imageName) :imageName(_imageName) {}
	virtual ~Render2DTexture(){}

private:
	std::string imageName;

public:
	void Render()override;
};

#endif 