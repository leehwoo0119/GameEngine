#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include <map>

class Scene;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

public:
	std::map<Scene*, int> scenes;

private:
	int sceneNumber;

public:
	void AddScene(Scene* _scene);
	void LoadScene(Scene* _scene);
};

#endif 
