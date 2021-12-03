#ifndef _TRIANGLERENDERER_H_
#define _TRIANGLERENDERER_H_
#include "Render2DPolygon.h"

class TriangleRenderer : public Render2DPolygon
{
public:
	TriangleRenderer();
	virtual ~TriangleRenderer();

public:
	void RenderPolygon(Vector3 _pos, Vector3 _scale)override;

	void Start(GameObject* _gameobject)override;
	void FixedUpdate(GameObject* _gameobject)override;
};

#endif 