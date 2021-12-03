#include "Scene.h"
#include "Time.h"
#include "GameObject.h"
#include "RendererManager.h"
#include <iostream>

Scene::Scene():sceneName()
{
	time = new Time();
}

Scene::Scene(std::string _scenename) : sceneName(_scenename)
{
    time = new Time();
}

Scene::~Scene()
{
	delete time;

    for (std::list<GameObject*>::iterator iter = gameObjects.begin();
        iter != gameObjects.end();
        iter++)
    {
        delete (*iter);
    }
}

void Scene::AddGameObject(GameObject* _object)
{
	gameObjects.emplace_back(_object);
}

void Scene::SceneStart()
{
    std::cout << sceneName << "¾ÀÀÇ SceneStart\n\n";
    for (std::list<GameObject*>::iterator object = gameObjects.begin();
        object != gameObjects.end(); object++)
    {
        (*object)->Start();
    }
}

void Scene::SceneLoop()
{
    SceneStart(); 

    while (true)
    {
        if (time)
        {
            time->StartTimer();     

            if (time->FixedUpdateCnt >= 1)
            {
              

                for (std::list<GameObject*>::iterator object = gameObjects.begin();
                    object != gameObjects.end(); object++)
                {                 
                    (*object)->FixedUpdate();
                }
                RendererManager::Instance()->RendererMgrRenderReset();
                RendererManager::Instance()->RendererMgrLoopEvent();
                time->FixedUpdateCnt = 0;
            }           
        }      
    }
}


