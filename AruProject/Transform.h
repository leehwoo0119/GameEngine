#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_
#include <list>
#include "Component.h"

class GameObject;

class Transform : public Component
{
public:
	Transform();
	virtual ~Transform();

public:
	std::list<Transform*> m_Childs;

	Transform* p_Parent;

	Vector3 position;
	Vector3 childFirstPosition;
	Vector3 scale;

public:
	void AddChild(Transform* _child);

	void SetPostion(Vector3 _vec);
	void SetScale(Vector3 _vec);
	void Translate(Vector3 _vector);

	void Start()override;
	void FixedUpdate()override;
};

#endif 
