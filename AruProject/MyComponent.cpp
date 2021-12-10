#include "MyComponent.h"
#include <iostream>
#include "ExecuteCoroutine.cpp"
#include "InputManager.h"

MyComponent::MyComponent()
{
	p_CoroutineTest = new ExecuteCoroutine<MyComponent>(this);
	p_WaitTime_1 = new WaitForSecondsTimer(2.0);
	p_WaitTime_2 = new WaitForSecondsTimer(5.0);
}

MyComponent::~MyComponent()
{
	delete p_WaitTime_1;
	delete p_CoroutineTest;
}

void MyComponent::CoroutineTest(ExecuteCoroutine<MyComponent>* _coroutine)
{
	if (!_coroutine)return;
	while (_coroutine->bLoop)
	{
		_coroutine->YieldReturn();					//디폴트 null
		if (_coroutine->ExecuteCoroutineState())
		{
			printf("CoroutineTest_1------------------------------Wait: 2.0------------------------------\n");
		}
		_coroutine->YieldReturn(p_WaitTime_1);		//p_WaitTime_1만큼 대기
		if (_coroutine->ExecuteCoroutineState())
		{
			printf("CoroutineTest_2------------------------------Wait: 5.0------------------------------\n");
		}
		_coroutine->YieldReturn(p_WaitTime_2);		//p_WaitTime_2만큼 대기
		if (_coroutine->ExecuteCoroutineState())
		{
			printf("CoroutineTest_3---------------------------------------------------------------------\n");
		}		
	}
}

void MyComponent::Start()
{	
	//Coroutine* cor = new Coroutine(([&]() {CoroutinePratice(); }));
	
	p_CoroutineTest->AddCoroutineFunc(&MyComponent::CoroutineTest);
}

void MyComponent::FixedUpdate()
{
	/*if(InputManager::Instance()->GetKeyDown('A'))
		printf("A\n");
	if (InputManager::Instance()->GetKeyDown('D'))
		printf("D\n");*/
}
void MyComponent::Coroutine()
{
	if (p_WaitTime_1 && p_WaitTime_2)
	{
		if(p_WaitTime_1->CoroutineUpdateTimer() && p_WaitTime_2 -> CoroutineUpdateTimer())
			p_CoroutineTest->StartCoroutine();
	}
}
