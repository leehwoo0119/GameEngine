#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include "IStartUpdate.h"
#include "Vector3.h"
#include <string>

class GameObject;

class Component :public IStartUpdate
{
public:
	Component();
	virtual~Component();

public:
	GameObject* p_GameObject;

 public:
	 void Awake()override {}
	 void Start()override {}
	 void FixedUpdate()override {}
	 void Update()override {}
	 void Coroutine()override {}
	 void LateUpdate()override {}
	 void Render()override {}
};

#endif 