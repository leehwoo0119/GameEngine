#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Vector3.h"

#include <iostream>

GameObject::GameObject() :gameObject(NULL)
{
}

GameObject::GameObject(std::string _name):gameObject(NULL)
{
	gameObject = this;
	this->name = _name;
	transform = new Transform();
	AddComponent(transform);
}

GameObject::~GameObject()
{
	delete transform;
	delete gameObject;

	for (std::list<Component*>::iterator iter = components.begin();
		iter != components.end();
		iter++)
	{
		delete (*iter);
	}
}

void GameObject::AddComponent(Component* _comp)
{
	components.emplace_back(_comp);
}

void GameObject::AddChild(GameObject* _child)
{
	childs.emplace_back(_child);
	_child->parent = this;
}

void GameObject::SetPostion(Vector3 _vec)
{
	if (!transform)return;

	if (this->parent != nullptr)
	{
		_vec += this->parent->transform->m_position;
	}

	transform->m_position = _vec;

}

void GameObject::SetScale(Vector3 _vec)
{
	if (!transform)return;

	if (this->parent != nullptr)
	{
		_vec *= this->parent->transform->m_scale;
	}

	transform->m_scale = _vec;
}

void GameObject::Start()
{
	for (std::list<Component*>::iterator comp = components.begin();
		comp != components.end(); comp++)
	{
		std::cout << name << "ÀÇ ";
		(*comp)->Start(this);
	}
}

void GameObject::FixedUpdate()
{
	for (std::list<Component*>::iterator comp = components.begin();
		comp != components.end(); comp++)
	{
		std::cout << name << "ÀÇ ";
		(*comp)->FixedUpdate(this);
	}
}



