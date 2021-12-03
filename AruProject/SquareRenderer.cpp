#include "SquareRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "OpenGLRenderer.h"

SquareRenderer::SquareRenderer()
{
}

SquareRenderer::~SquareRenderer()
{
}

void SquareRenderer::RenderPolygon(Vector3 _pos, Vector3 _scale)
{
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex2f(_pos.x - (_scale.x / 2), _pos.y - (_scale.y / 2));
	glVertex2f(_pos.x + (_scale.x / 2), _pos.y - (_scale.y / 2));
	glVertex2f(_pos.x + (_scale.x / 2), _pos.y + (_scale.y / 2));
	glVertex2f(_pos.x - (_scale.x / 2), _pos.y + (_scale.y / 2));
	glEnd();
	glFinish();
	glPopMatrix();
}

void SquareRenderer::Start(GameObject* _gameobject)
{
	RenderPolygon(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}

void SquareRenderer::FixedUpdate(GameObject* _gameobject)
{
	RenderPolygon(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}

