#include "MyComponent.h"
#include <iostream>

void MyComponent::Start(GameObject* _gameobject)
{
	std::cout << "MyComponent Start" << std::endl;
}

void MyComponent::FixedUpdate(GameObject* _gameobject)
{
	std::cout << "MyComponent FixedUpdate" << std::endl;
}
