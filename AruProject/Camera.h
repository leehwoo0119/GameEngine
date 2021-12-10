#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "Component.h"

class Vector3;

class Camera :public Component
{
public:
	Camera(){}
	~Camera(){}

public:
	Vector3 GetCameraPosition()const;
};

#endif 