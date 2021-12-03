#include "Render2DTexture.h"
#include "GameObject.h"
#include "Transform.h"
#include "OpenGLRenderer.h"
#include "RendererManager.h"

Render2DTexture::Render2DTexture(int _imagetype) :imageType(_imagetype)
{
}

void Render2DTexture::RenderTexture(Vector3 _pos, Vector3 _scale)
{
    glLoadIdentity();
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, RendererManager::Instance()->RendererMgrGetMyTextureObject(imageType));
    glBegin(GL_QUADS);	
    glTexCoord2f(0.0f, 0.0f);   glVertex2f(_pos.x - (_scale.x / 2), _pos.y - (_scale.y / 2));
    glTexCoord2f(1.0f, 0.0f);   glVertex2f(_pos.x + (_scale.x / 2), _pos.y - (_scale.y / 2));
    glTexCoord2f(1.0f, 1.0f);   glVertex2f(_pos.x + (_scale.x / 2), _pos.y + (_scale.y / 2));
    glTexCoord2f(0.0f, 1.0f);   glVertex2f(_pos.x - (_scale.x / 2), _pos.y + (_scale.y / 2));
    glEnd();
    glFinish();
    glPopMatrix();
}

void Render2DTexture::Start(GameObject* _gameobject)
{
    RenderTexture(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}

void Render2DTexture::FixedUpdate(GameObject* _gameobject)
{
    RenderTexture(_gameobject->transform->m_position, _gameobject->transform->m_scale);
}