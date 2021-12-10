#include "InputManager.h"
#include<windows.h>

bool InputManager::GetKeyDown(unsigned char _key)
{
	if (GetAsyncKeyState(_key))
		return true;
	return false;
}

