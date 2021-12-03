#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include "Vector3.h"
#include "Component.h"

class GameObject;

class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

public:
	Vector3 m_position;
	Vector3 m_scale;

public:
	void Translate(GameObject* _gameobject, Vector3 _vector);

	void Start(GameObject* _gameobject)override;
	void FixedUpdate(GameObject* _gameobject)override;
};

#endif 
