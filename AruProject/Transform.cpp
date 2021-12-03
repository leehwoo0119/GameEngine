#include "Transform.h"
#include "GameObject.h"
#include <iostream>

Transform::Transform()
{
	m_position.x = 0.0;
	m_position.y = 0.0;
	m_position.z = 0.0;
	m_scale.x = 1.0;
	m_scale.y = 1.0;
	m_scale.z = 1.0;
}

Transform::~Transform()
{
}

void Transform::Translate(GameObject* _gameobject, Vector3 _vector)
{
	_gameobject->SetPostion(_vector);
}

void Transform::Start(GameObject* _gameobject)
{
	std::cout << "ÁÂÇ¥ : (" << m_position.x << " , " << m_position.y << " , " << m_position.z << ")" << std::endl;
	std::cout << "       Å©±â : (" << m_scale.x << " , " << m_scale.y << " , " << m_scale.z << ")" << std::endl << std::endl;
}

void Transform::FixedUpdate(GameObject* _gameobject)
{
	std::cout << "ÁÂÇ¥ : (" << m_position.x << " , " << m_position.y << " , " << m_position.z << ")" << std::endl;
	std::cout << "       Å©±â : (" << m_scale.x << " , " << m_scale.y << " , " << m_scale.z << ")" << std::endl << std::endl;
}