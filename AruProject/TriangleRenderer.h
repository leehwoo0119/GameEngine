#ifndef _TRIANGLERENDERER_H_
#define _TRIANGLERENDERER_H_
#include "Component.h"

class TriangleRenderer : public Component
{
public:
	TriangleRenderer() {}
	virtual ~TriangleRenderer() {}

public:
	void Render()override;
};

#endif 