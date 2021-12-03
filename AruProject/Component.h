#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include "IStartUpdate.h"
#include "Object.h"

class Component : public Object, public IStartUpdate
{
public:
	Component();
	virtual~Component();

public:
	void Start(GameObject* _gameobject)override {}
	void FixedUpdate(GameObject* _gameobject)override {}
};

#endif 