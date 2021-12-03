#ifndef _MONOBEHAIVOR_H_
#define _MONOBEHAIVOR_H_
#include "Component.h"

class MonoBehaviour : public Component
{
public:
	MonoBehaviour();
	virtual~MonoBehaviour();
	
public:
	bool bEnable;

public:
	void Start(GameObject* _gameobject)override {}
	void FixedUpdate(GameObject* _gameobject)override {}
};

#endif 