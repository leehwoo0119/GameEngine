#include "SceneManager.h"
#include "Scene.h"
#include "Time.h"
#include "RendererManager.h"
#include "InputManager.h"

SceneManager::SceneManager():p_CurScene(nullptr), bSceneLoop(true)
{
}

SceneManager::~SceneManager()
{
	for (std::map<Scene*, std::string>::iterator iter = m_Scenes.begin();
		iter != m_Scenes.end();
		iter++)
	{
		delete iter->first;
	}
	m_Scenes.clear();
}

void SceneManager::AddScene(Scene* _scene)
{
	m_Scenes.insert(std::pair<Scene*, std::string>(_scene, _scene->sceneName));
}

bool SceneManager::LoadScene(Scene* _scene)
{
	if (_scene == nullptr)return false;
		
	p_CurScene = _scene;
	SceneLoop(_scene);
	return true;
}

void SceneManager::SceneLoop(Scene* _scene)
{
	_scene->Hierarchy();
	_scene->SceneAwake();
	_scene->SceneStart();

	while (bSceneLoop)
	{
		Time::Instance()->UpdateTimer();
		//50프레임
		if (Time::Instance()->FixedUpdateTimer())
		{
			_scene->SceneFixedUpdate();
		}
		_scene->SceneUpdate();
		_scene->SceneCoroutine();
		_scene->SceneLateUpdate();
		//60프레임
		if (Time::Instance()->RenderUpdateTimer())
		{
			_scene->SceneRender();
			RendererManager::Instance()->RendererMgrLoopEvent();
		}
	}
}

Scene* SceneManager::GetSceneFindName(std::string _sceneName)
{
	for (std::map<Scene*, std::string>::iterator iter = m_Scenes.begin();
		iter != m_Scenes.end();
		iter++)
	{
		if (iter->second == _sceneName)
		{
			return iter->first;
			break;
		}
	}
	return nullptr;
}
