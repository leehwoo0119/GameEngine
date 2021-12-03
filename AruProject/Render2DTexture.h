#ifndef _RENDER2DTEXTURE_H_
#define _RENDER2DTEXTURE_H_

#include "Vector3.h"
#include "Component.h"

class Render2DTexture : public Component
{
public:
	Render2DTexture(int _imagetype);
	virtual ~Render2DTexture(){}
private:
	int imageType;

public:
	void RenderTexture(Vector3 _pos, Vector3 _scale);

	void Start(GameObject* _gameobject)override;
	void FixedUpdate(GameObject* _gameobject)override;
};

#endif 