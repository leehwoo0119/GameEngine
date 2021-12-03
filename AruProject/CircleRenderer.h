#ifndef _CIRCLERENDERER_H_
#define _CIRCLERENDERER_H_
#include "Render2DPolygon.h"

class CircleRenderer : public Render2DPolygon
{
public:
	CircleRenderer();
	virtual ~CircleRenderer();

public:
	void RenderPolygon(Vector3 _pos, Vector3 _scale)override;

	void Start(GameObject* _gameobject)override;
	void FixedUpdate(GameObject* _gameobject)override;
};

#endif 