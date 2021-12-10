#ifndef _MYCOMPONENT_H_
#define _MYCOMPONENT_H_

#include "MonoBehaviour.h"

template<typename T> class ExecuteCoroutine;
class WaitForSecondsTimer;

class MyComponent : public MonoBehaviour
{
public:
	MyComponent();
	virtual ~MyComponent();

public:
	ExecuteCoroutine<MyComponent>* p_CoroutineTest;
	WaitForSecondsTimer* p_WaitTime_1;
	WaitForSecondsTimer* p_WaitTime_2;
	
public:
	void Start()override;
	void FixedUpdate()override;
	void Coroutine()override;

	void CoroutineTest(ExecuteCoroutine<MyComponent>* _coroutine);
};

#endif 
