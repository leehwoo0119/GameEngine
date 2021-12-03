#ifndef _ISTARTUPDATE_H_
#define _ISTARTUPDATE_H_

class GameObject;

__interface IStartUpdate
{
public:
	virtual void Start(GameObject* _gameobject) = 0;
	virtual void FixedUpdate(GameObject* _gameobject) = 0;
};

#endif 