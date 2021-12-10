#include "Camera.h"
#include "Vector3.h"
#include "GameObject.h"
#include "Transform.h"

Vector3 Camera::GetCameraPosition() const
{ 
	return p_GameObject->p_Transform->position;
}
