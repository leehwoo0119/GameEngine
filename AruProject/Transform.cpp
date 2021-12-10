#include "Transform.h"
#include "GameObject.h"
#include <iostream>

Transform::Transform()
{
	position.x = 0.0;
	position.y = 0.0;
	position.z = 0.0;
	scale.x = 1.0;
	scale.y = 1.0;
	scale.z = 1.0;
}

Transform::~Transform()
{
}

void Transform::AddChild(Transform* _child)
{
	m_Childs.emplace_back(_child);
	_child->p_Parent = this;
	_child->SetPostion(_child->position + position);
	_child->childFirstPosition = _child->position + position;
	_child->SetScale(_child->scale * scale);
}

void Transform::SetPostion(Vector3 _vec)
{
	position = _vec;
}

void Transform::SetScale(Vector3 _vec)
{
	scale = _vec;
	if (!m_Childs.empty())
	{
		for (auto childs : m_Childs)
		{
			childs->scale *= scale;
		}
	}
}
void Transform::Translate(Vector3 _vector)
{
	if (!m_Childs.empty())
	{
		for (auto childs : m_Childs)
		{
			childs->SetPostion(childs->childFirstPosition + position + _vector);
		}
	}
	SetPostion(position + _vector);
}

void Transform::Start()
{
	//std::cout << "ÁÂÇ¥ : (" << m_position.x << " , " << m_position.y << " , " << m_position.z << ")" << std::endl;
	//std::cout << "       Å©±â : (" << m_scale.x << " , " << m_scale.y << " , " << m_scale.z << ")" << std::endl << std::endl;
}

void Transform::FixedUpdate()
{
	//std::cout << "ÁÂÇ¥ : (" << m_position.x << " , " << m_position.y << " , " << m_position.z << ")" << std::endl;
	//std::cout << "       Å©±â : (" << m_scale.x << " , " << m_scale.y << " , " << m_scale.z << ")" << std::endl << std::endl;
}