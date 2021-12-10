#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_
#include <string>

class InputManager
{
private:
	InputManager() {};
	~InputManager() {};

public:
	static InputManager* Instance()
	{
		static InputManager instance;
		return &instance;
	}

public:
	bool GetKeyDown(unsigned char _key);
};

#endif 