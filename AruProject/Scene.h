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
	Scene(std::string _scenename);
	~Scene();

private:
	std::string sceneName;
	Time* time;	

public:
	std::list<GameObject*> gameObjects;

public:
	void AddGameObject(GameObject* _object);

	void SceneStart();
	void SceneLoop();
};

#endif 
