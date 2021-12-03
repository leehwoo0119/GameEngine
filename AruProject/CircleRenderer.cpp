#include "CircleRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "OpenGLRenderer.h"

CircleRenderer::CircleRenderer()
{
}

CircleRenderer::~CircleRenderer()
{
}

void CircleRenderer::RenderPolygon(Vector3 _pos, Vector3 _scale)
{
	glPushMatrix();
	//glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	float radiusX = _scale.x;
	float radiusY = _scale.y;

	for (int i = 0; i < 360; i++)
	{
		double angle = i * 3.141592 / 180;
		double x = radiusX * cos(angle);
		double y = radiusY * sin(angle);
		glVertex2f(x + _pos.x, y + _pos.y);
	}
	glEnd();
	glFinish();
	glPopMatrix();
}

void CircleRenderer::Start(GameObject* _gameobject)
{
    RenderPolygon(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}

void CircleRenderer::FixedUpdate(GameObject* _gameobject)
{
    RenderPolygon(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}

