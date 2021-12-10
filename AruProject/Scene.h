#ifndef _SCENE_H_
#define _SCENE_H_
#include "list"
#include <string>

class Time;
class GameObject;

class Scene
{
public:
	Scene();
	~Scene();

public:
	std::string sceneName;

public:
	std::list<GameObject*> m_GameObjects;

public:
	virtual void Hierarchy() = 0;

	GameObject* AddGameObject(GameObject* _object);

	void SceneAwake();
	void SceneStart();
	void SceneFixedUpdate();
	void SceneUpdate();
	void SceneCoroutine();
	void SceneLateUpdate();
	void SceneRender();
};

#endif 
