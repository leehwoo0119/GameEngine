#include "TriangleRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "OpenGLRenderer.h"
#include "RendererManager.h"

TriangleRenderer::TriangleRenderer()
{
}

TriangleRenderer::~TriangleRenderer()
{
}

void TriangleRenderer::RenderPolygon(Vector3 _pos, Vector3 _scale)
{
	//RendererManager::Instance()->GetRenderer()== 
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	glVertex2f(_pos.x - (_scale.x / 2), _pos.y - (_scale.y / 2));
	glVertex2f(_pos.x + (_scale.x / 2), _pos.y - (_scale.y / 2));
	glVertex2f(_pos.x, _pos.y + (_scale.y / 2));
	glEnd();
	glFinish();
	glPopMatrix();
}

void TriangleRenderer::Start(GameObject* _gameobject)
{
	RenderPolygon(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}

void TriangleRenderer::FixedUpdate(GameObject* _gameobject)
{
	RenderPolygon(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}
