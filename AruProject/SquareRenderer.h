#ifndef _SQARERENDERER_H_
#define _SQARERENDERER_H_
#include "Component.h"

class SquareRenderer : public Component
{
public:
	SquareRenderer() {}
	virtual ~SquareRenderer() {}

public:	
	void Render()override;
};

#endif 