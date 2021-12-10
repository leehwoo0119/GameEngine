#ifndef _CIRCLERENDERER_H_
#define _CIRCLERENDERER_H_
#include "Component.h"

class CircleRenderer : public Component
{
public:
	CircleRenderer() {}
	virtual ~CircleRenderer() {}

public:
	void Render()override;
};

#endif 