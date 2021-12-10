#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_
#include <map>
#include <string>

class Scene;

class SceneManager
{
private:
	SceneManager();
	~SceneManager();

public:
public:
	static SceneManager* Instance()
	{
		static SceneManager instance;
		return &instance;
	}

public:
	std::map<Scene*, std::string> m_Scenes;

private:
	Scene* p_CurScene;
	bool bSceneLoop;

public:
	void AddScene(Scene* _scene);
	bool LoadScene(Scene* _scene);
	void SceneLoop(Scene* _scene);
	Scene* GetSceneFindName(std::string _sceneName);
};

#endif 
