#pragma once
#include "MonoBehaviour.h"

class MyComponent : public MonoBehaviour
{
public:
    void Start(GameObject* _gameobject)override;
    void FixedUpdate(GameObject* _gameobject)override;
};

