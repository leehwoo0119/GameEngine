#ifndef _CUSTOMSCENE_H_
#define _CUSTOMSCENE_H_

#include "Scene.h"

class CustomScene : public Scene
{
public:
	CustomScene(std::string _sceneName);
	virtual ~CustomScene() {}

public:
	void Hierarchy() override;
};

#endif 