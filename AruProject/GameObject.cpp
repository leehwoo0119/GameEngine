#include "GameObject.h"
#include "Component.h"
#include "Transform.h"
#include "Vector3.h"

GameObject::GameObject(std::string _name):p_GameObject(NULL)
{
	p_GameObject = this;
	this->name = _name;
	AddComponent(new Transform());
	p_Transform = GetComponent<Transform>();
}

GameObject::~GameObject()
{
	delete p_Transform;
	delete p_GameObject;

	for (std::list<Component*>::iterator iter = m_Components.begin();
		iter != m_Components.end();
		iter++)
	{
		delete (*iter);
	}
}

void GameObject::AddComponent(Component* _comp)
{
	m_Components.emplace_back(_comp);
	_comp->p_GameObject = this;
}

void GameObject::Awake()
{
	for (std::list<Component*>::iterator comp = m_Components.begin();
		comp != m_Components.end(); comp++)
	{
		(*comp)->Awake();
	}
}

void GameObject::Start()
{
	for (std::list<Component*>::iterator comp = m_Components.begin();
		comp != m_Components.end(); comp++)
	{
		(*comp)->Start();
	}
}

void GameObject::FixedUpdate()
{
	for (std::list<Component*>::iterator comp = m_Components.begin();
		comp != m_Components.end(); comp++)
	{
		(*comp)->FixedUpdate();
	}
}

void GameObject::Update()
{
	for (std::list<Component*>::iterator comp = m_Components.begin();
		comp != m_Components.end(); comp++)
	{
		(*comp)->Update();
	}
}

void GameObject::Coroutine()
{
	for (std::list<Component*>::iterator comp = m_Components.begin();
		comp != m_Components.end(); comp++)
	{
		(*comp)->Coroutine();
	}
}

void GameObject::LateUpdate()
{
	for (std::list<Component*>::iterator comp = m_Components.begin();
		comp != m_Components.end(); comp++)
	{
		(*comp)->LateUpdate();
	}
}

void GameObject::Render()
{
	for (std::list<Component*>::iterator comp = m_Components.begin();
		comp != m_Components.end(); comp++)
	{
		(*comp)->Render();
	}
}



