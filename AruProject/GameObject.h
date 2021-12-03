#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "Object.h"
#include <list>
#include "Render2DPolygon.h"

class Component;
class Transform;
class Vector3;

class GameObject : public Object
{
public:
	GameObject();
	GameObject(std::string _name);
	~GameObject();

public:
	std::list<Component*> components;
	std::list<GameObject*> childs;

	GameObject* parent;
	GameObject* gameObject;
	Transform* transform;

public:
	void AddComponent(Component* _comp);
	void AddChild(GameObject* _child);

	void SetPostion(Vector3 _vec);
	void SetScale(Vector3 _vec);

	void Start();
	void FixedUpdate();
};

#endif 
