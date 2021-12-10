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
	//������Ʈ �˻�� 0����
	curState = 0;																		
	bLoop = true;
	//Ŀ���� ������Ʈ void*(���ø�)�Լ� ����
	(p_customComponent->*p_coroutineFunc)(this);
}

template<typename T>
void ExecuteCoroutine<T>::YieldReturn(WaitForSecondsTimer* _timer)
{	
	//�̹� YieldReturn����
	if (bYieldReturnDelay)
	{
		//YieldReturn���¸� �����ߴ� ������ �ٽ� ���ƿ���(���� ������) YieldReturn���¸� ������
		if (yieldState == curState)
		{
			coroutineState = CoroutineState::EMoveNext;
			bYieldReturnDelay = false;
		}
	}
	else
	{
		//YieldReturn���°� �ƴ϶�� _timer���θ� Ȯ��
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
	//YieldReturn���°� �ƴ϶�� ���� �����Ӷ� �˻縦 ���� yieldState������ ��������
	if (!bYieldReturnDelay)
	{
		yieldState = curState;
		bYieldReturnDelay = true;
		bLoop = false;
	}
	//YieldReturn���¶�� �ش� �ڵ� �����ϰ� ���� ������Ʈ�� �̵�
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
