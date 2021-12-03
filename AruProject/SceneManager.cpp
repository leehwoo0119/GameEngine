#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager():sceneNumber(0)
{
}

SceneManager::~SceneManager()
{
	for (std::map<Scene*, int>::iterator iter = scenes.begin();
		iter != scenes.end();
		iter++)
	{
		delete iter->first;
	}
	scenes.clear();
}

void SceneManager::AddScene(Scene* _scene)
{
	scenes.insert(std::pair<Scene*, int>(_scene, sceneNumber));
	sceneNumber++;
}

void SceneManager::LoadScene(Scene* _scene)
{
	_scene->SceneLoop();
}
