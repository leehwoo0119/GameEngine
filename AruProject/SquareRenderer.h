#ifndef _SQARERENDERER_H_
#define _SQARERENDERER_H_
#include "Render2DPolygon.h"

class SquareRenderer : public Render2DPolygon
{
public:
	SquareRenderer();
	virtual ~SquareRenderer();

public:
	void RenderPolygon(Vector3 _pos, Vector3 _scale)override;
	
	void Start(GameObject* _gameobject)override;
	void FixedUpdate(GameObject* _gameobject)override;
};

#endif 