#include "MyCameraCtrl.h"
#include "RendererManager.h"
#include "GameObject.h"
#include "Camera.h"
#include "Transform.h"
#include "Time.h"
#include "InputManager.h"

MyCameraCtrl::MyCameraCtrl()
{
	p_Camera = nullptr;
	cameraSpeed = 0.5f;
}

MyCameraCtrl::~MyCameraCtrl()
{
	delete p_Camera;
}

void MyCameraCtrl::Start()
{
	p_Camera = p_GameObject->GetComponent<Camera>();
	if(p_Camera)
		RendererManager::Instance()->SetCamera(p_Camera);
}

void MyCameraCtrl::LateUpdate()
{
	if (p_Camera)
	{
		if (InputManager::Instance()->GetKeyDown('W'))
		{
			p_Camera->p_GameObject->p_Transform->Translate(Vector3(0, cameraSpeed * DELTA_TIME, 0));
		}
		if (InputManager::Instance()->GetKeyDown('S'))
		{
			p_Camera->p_GameObject->p_Transform->Translate(Vector3(0, -cameraSpeed * DELTA_TIME, 0));
		}
	}
}
