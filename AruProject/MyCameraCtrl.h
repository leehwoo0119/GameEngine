#ifndef _MYCAMERACTRL_H_
#define _MYCAMERACTRL_H_
#include "MonoBehaviour.h"

class Camera;

class MyCameraCtrl :public MonoBehaviour
{
public:
	MyCameraCtrl();
	virtual ~MyCameraCtrl();

private:
	Camera* p_Camera;
	float cameraSpeed;

public:
	void Start()override;
	void LateUpdate()override;
};

#endif 
