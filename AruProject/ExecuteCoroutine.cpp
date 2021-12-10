#include "ExecuteCoroutine.h"
#include "MyComponent.h"
#include "WaitForSecondsTimer.h"

template<typename T>
void ExecuteCoroutine<T>::AddCoroutineFunc(void (T::* _pFunc)(ExecuteCoroutine*))
{
	p_coroutineFunc = _pFunc;
}

template<typename T>
void ExecuteCoroutine<T>::StartCoroutine()
{
	if (!p_coroutineFunc)return;
	//스테이트 검사는 0부터
	curState = 0;																		
	bLoop = true;
	//커스텀 컴포넌트 void*(템플릿)함수 실행
	(p_customComponent->*p_coroutineFunc)(this);
}

template<typename T>
void ExecuteCoroutine<T>::YieldReturn(WaitForSecondsTimer* _timer)
{	
	//이미 YieldReturn상태
	if (bYieldReturnDelay)
	{
		//YieldReturn상태를 시작했던 곳으로 다시 돌아오면(다음 프레임) YieldReturn상태를 끝낸다
		if (yieldState == curState)
		{
			coroutineState = CoroutineState::EMoveNext;
			bYieldReturnDelay = false;
		}
	}
	else
	{
		//YieldReturn상태가 아니라면 _timer여부를 확인
		if (_timer)
		{
			_timer->SetWait();
		}
		coroutineState = CoroutineState::EYieldReturn;
	}
}

template<typename T>
void ExecuteCoroutine<T>::YieldReturnState()
{
	//YieldReturn상태가 아니라면 다음 프레임때 검사를 위해 yieldState저장후 루프종료
	if (!bYieldReturnDelay)
	{
		yieldState = curState;
		bYieldReturnDelay = true;
		bLoop = false;
	}
	//YieldReturn상태라면 해당 코드 무시하고 다음 스테이트로 이동
	CheckNextState();
}

template<typename T>
void ExecuteCoroutine<T>::MoveNext()
{
	CheckNextState();
}

template<typename T>
void ExecuteCoroutine<T>::CheckNextState()
{
	curState++;
}

template<typename T>
bool ExecuteCoroutine<T>::ExecuteCoroutineState()
{
	//printf("curState: %d\n", curState);
	switch (coroutineState)
	{
	case CoroutineState::EMoveNext:
		MoveNext();	
		return true;
		break;
	case CoroutineState::EYieldReturn:
		YieldReturnState();
		return false;
		break;
	}
	return false;
}
