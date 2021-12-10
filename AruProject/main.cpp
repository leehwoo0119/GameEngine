#include "SceneManager.h"
#include "CustomScene.h"
#include "OpenGLRenderer.h"
#include "RendererManager.h"
#include "AruEngineSetting.h"
#include <assert.h> 
#include <string>
#include <iostream>

int main(int argc, char** argv)
{
	AruEngineSetting setting
	(600, 600, 
	new OpenGLRenderer(), 
	"AruEngine");

	try
	{
		if (!RendererManager::Instance()->
			RendererMgrInit(argc, argv, setting))
		{
			throw std::string("Init세팅 실패\n");
		}
	}
	catch (std::string& _errorMessage)
	{
		std::cout << _errorMessage << "\n";
		return 0;
	}

	SceneManager::Instance()->
	AddScene(new CustomScene("Test_1Scene"));

	try
	{
		if (!SceneManager::Instance()->
			LoadScene(SceneManager::Instance()->
				GetSceneFindName("Test_1Scene")))
		{
			throw std::string("씬 불러오기 실패\n");
		}
	}
	catch (std::string& _errorMessage)
	{
		std::cout << _errorMessage << "\n";
		return 0;
	}

	return 0;
}