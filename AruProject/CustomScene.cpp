#include "CustomScene.h"
#include "GameObject.h"
#include "MyComponent.h"
#include "SquareRenderer.h"
#include "Render2DTexture.h"
#include "CircleRenderer.h"
#include "RendererManager.h"
#include "Transform.h"
#include "Camera.h"
#include "MyCameraCtrl.h"
#include "SkyScroll.h"

CustomScene::CustomScene(std::string _sceneName)
{
	sceneName = _sceneName;
}

void CustomScene::Hierarchy()
{
	//잘못된 경로
	RendererManager::Instance()->GetRenderer()->AddTexture("apple.bmp", "apple");
	RendererManager::Instance()->GetRenderer()->AddTexture("Assets/SkyTileSprite.bmp","SkyTileSprite");
	RendererManager::Instance()->GetRenderer()->AddTexture("Assets/GrassThinSprite.bmp", "GrassThinSprite");

	RendererManager::Instance()->GetRenderer()->LoadGLTextures();

	GameObject* MainCamera = AddGameObject(new GameObject("MainCamera"));
	MainCamera->AddComponent(new Camera());
	MainCamera->AddComponent(new MyCameraCtrl());

	GameObject* groundObj = AddGameObject(new GameObject("groundObj"));
	groundObj->AddComponent(new Render2DTexture("GrassThinSprite"));
	groundObj->p_Transform->SetPostion(Vector3(0.0f, -0.475f, 0.0f));
	groundObj->p_Transform->SetScale(Vector3(2.0f, 1.5f, 0.0f));

	//부모
	GameObject* parents_SkyObj = AddGameObject(new GameObject("parents_SkyObj"));
	parents_SkyObj->AddComponent(new SkyScroll());
	parents_SkyObj->p_Transform->SetPostion(Vector3(0.0f, 0.0f, 0.0f));
		//자식
		{
			GameObject* skyObj_1 = AddGameObject(new GameObject("skyObj_1"));
			skyObj_1->AddComponent(new Render2DTexture("SkyTileSprite"));
			skyObj_1->p_Transform->SetPostion(Vector3(0.0f, 0.0f, 0.0f));
			skyObj_1->p_Transform->SetScale(Vector3(2.0f, 1.0f, 0.0f));
			parents_SkyObj->p_Transform->AddChild(skyObj_1->p_Transform);

			GameObject* skyObj_2 = AddGameObject(new GameObject("skyObj_2"));
			skyObj_2->AddComponent(new Render2DTexture("SkyTileSprite"));
			skyObj_2->p_Transform->SetPostion(Vector3(2.0f, 0.0f, 0.0f));
			skyObj_2->p_Transform->SetScale(Vector3(2.0f, 1.0f, 0.0f));
			parents_SkyObj->p_Transform->AddChild(skyObj_2->p_Transform);
		}
	GameObject* obj1 = AddGameObject(new GameObject("obj1"));
	obj1->AddComponent(new MyComponent());
	obj1->AddComponent(new CircleRenderer());
	obj1->p_Transform->SetPostion(Vector3(-0.6f, -0.35f, 0.0f));
	obj1->p_Transform->SetScale(Vector3(0.1f, 0.1f, 0.0f));
}
