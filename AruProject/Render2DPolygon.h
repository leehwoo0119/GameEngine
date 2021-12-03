#ifndef _RENDERER2DPOLYGON_H_
#define _RENDERER2DPOLYGON_H_

#include "Vector3.h"
#include "Component.h"

class Render2DPolygon : public Component
{
public:
	virtual void RenderPolygon(Vector3 _pos, Vector3 _scale) = 0;
	
	void Start(GameObject* _gameobject)override {}
	void FixedUpdate(GameObject* _gameobject)override {}
};

#endif 