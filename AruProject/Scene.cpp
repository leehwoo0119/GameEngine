#include "Scene.h"
#include "GameObject.h"
#include <iostream>
#include <windows.h>

Scene::Scene():sceneName()
{
}

Scene::~Scene()
{
    for (std::list<GameObject*>::iterator iter = m_GameObjects.begin();
        iter != m_GameObjects.end();
        iter++)
    {
        delete (*iter);
    }
}

GameObject* Scene::AddGameObject(GameObject* _object)
{
	m_GameObjects.emplace_back(_object);
    return _object;
}

void Scene::SceneAwake()
{ 
    //std::cout << sceneName << "¾ÀÀÇ SceneAwake\n\n";
    for (std::list<GameObject*>::iterator object = m_GameObjects.begin();
        object != m_GameObjects.end(); object++)
    {
        (*object)->Awake();
    }
}

void Scene::SceneStart()
{
    //std::cout << sceneName << "¾ÀÀÇ SceneStart\n\n";
    for (std::list<GameObject*>::iterator object = m_GameObjects.begin();
        object != m_GameObjects.end(); object++)
    {
        (*object)->Start();
    }
}

void Scene::SceneFixedUpdate()
{
    //std::cout << sceneName << "¾ÀÀÇ SceneFixedUpdate\n\n";
    for (std::list<GameObject*>::iterator object = m_GameObjects.begin();
        object != m_GameObjects.end(); object++)
    {
        (*object)->FixedUpdate();
    }
}

void Scene::SceneUpdate()
{  
    //std::cout << sceneName << "¾ÀÀÇ SceneUpdate\n\n";
    for (std::list<GameObject*>::iterator object = m_GameObjects.begin();
        object != m_GameObjects.end(); object++)
    {
        (*object)->Update();
    }
}

void Scene::SceneCoroutine()
{
    for (std::list<GameObject*>::iterator object = m_GameObjects.begin();
        object != m_GameObjects.end(); object++)
    {
        (*object)->Coroutine();
    }
}

void Scene::SceneLateUpdate()
{  
    //std::cout << sceneName << "¾ÀÀÇ SceneLateUpdate\n";
    for (std::list<GameObject*>::iterator object = m_GameObjects.begin();
        object != m_GameObjects.end(); object++)
    {     
        (*object)->LateUpdate();
    }
}

void Scene::SceneRender()
{   
    //std::cout << sceneName << "¾ÀÀÇ Render\n\n";
    for (std::list<GameObject*>::iterator object = m_GameObjects.begin();
        object != m_GameObjects.end(); object++)
    {
        (*object)->Render();
    }
}
