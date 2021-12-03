#include "MyComponent.h"
#include "GameObject.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Vector3.h"
#include "SquareRenderer.h"
#include "TriangleRenderer.h"
#include "CircleRenderer.h"
#include "OpenGLRenderer.h"
#include "IRenderer.h"
#include "RendererManager.h"
#include "Render2DTexture.h"
#include "Transform.h"

int main(int argc, char** argv)
{
	IRenderer* rendererTools = new OpenGLRenderer();

	rendererTools->AddTexture("apple.bmp");
	rendererTools->AddTexture("flower.bmp");

	RendererManager::Instance()->SetRenderer(rendererTools);
	RendererManager::Instance()->RendererMgrInit(argc, argv);

	SceneManager* sceneManager = new SceneManager();

	Scene* Test1 = new Scene("Test_1Scene");

	GameObject* obj1 = new GameObject("obj1");
	Test1->AddGameObject(obj1);
	obj1->AddComponent(new MyComponent());
	obj1->AddComponent(new SquareRenderer());
	obj1->AddComponent(new Render2DTexture(0));
	obj1->SetPostion(Vector3(0.0f, 0.0f, 0.5f));
	obj1->SetScale(Vector3(1.9f, 1.9f, 0.1f));	


	GameObject* obj2 = new GameObject("obj2");
	Test1->AddGameObject(obj2);
	obj1->AddChild(obj2);
	obj2->AddComponent(new MyComponent());
	obj2->AddComponent(new CircleRenderer());
	obj2->SetPostion(Vector3(-1.0f, 0.0f, -1.0f));
	obj2->SetScale(Vector3(0.05f, 0.05f, 1.0f));	
	obj2->transform->Translate(obj2, Vector3(-0.5f, 0.0f, 0.0f));

	GameObject* obj3 = new GameObject("obj3");
	Test1->AddGameObject(obj3);
	obj3->AddComponent(new MyComponent());
	obj3->AddComponent(new TriangleRenderer());
	obj3->AddComponent(new Render2DTexture(1));
	obj3->SetPostion(Vector3(0.5f, 0.0f, 0.5f));
	obj3->SetScale(Vector3(0.8f, 0.8f, 0.1f));
	
	sceneManager->AddScene(Test1);

	//Scene* Test2 = new Scene("Test_2Scene");
	//Test2->AddGameObject(obj1);
	//sceneManager->AddScene(Test2);
	if (rendererTools->LoadGLTextures())
	{
		sceneManager->LoadScene(Test1);
	}	

	delete rendererTools;
	delete obj1;
	delete obj2;
	delete obj3;
	//delete obj4;
	delete sceneManager;
	delete Test1;

	return 0;
}