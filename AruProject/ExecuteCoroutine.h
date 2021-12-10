#ifndef _EXECUTECOROUTINE_H_
#define _EXECUTECOROUTINE_H_

#include <string>
#include "MyComponent.h"
class WaitForSecondsTimer;

enum CoroutineState
{
	EMoveNext=0,
	EYieldReturn
};
template<typename T>
class ExecuteCoroutine
{
public:
	ExecuteCoroutine(T* _comp) :curState(0), yieldState(0), bYieldReturnDelay(false), p_coroutineFunc(nullptr)
	{
		p_customComponent = _comp;
		coroutineState = CoroutineState::EMoveNext();
	}
	~ExecuteCoroutine() {}

public:											
	unsigned int curState;											//검사중인 스테이트(조건과 상관없이 증가하는)
	unsigned int yieldState;										//YieldReturn 상태일시 해당 스테이트 저장(다음 프레임때 검사를 위해)
	bool bLoop = false;												//코루틴 루프 체크(YieldReturn 상태일시 루프 종료후 메인으로 우선권 양도)

private:
	void (T::* p_coroutineFunc)(ExecuteCoroutine*);					//T(Component)::void(ExecuteCoroutine*) 형 함수 포인터
	bool bYieldReturnDelay;											//YieldReturnDelay시 1프레임 Delay
	T* p_customComponent;
	CoroutineState coroutineState;

public:
	void AddCoroutineFunc(void (T::* _pFunc)(ExecuteCoroutine*));	//유저가 커스텀한 컴포넌트에서 T(Component)::void포인터형 함수 추가 
	void StartCoroutine();
	void YieldReturn(WaitForSecondsTimer* _time = nullptr);			//YieldReturn(nullptr)==한프레임 대기,YieldReturn(_time)_time만큼 대기	
	bool ExecuteCoroutineState();											

private:
	void YieldReturnState();
	void MoveNext();
	void CheckNextState();
};

#endif 
