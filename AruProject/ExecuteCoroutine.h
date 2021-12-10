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
	unsigned int curState;											//�˻����� ������Ʈ(���ǰ� ������� �����ϴ�)
	unsigned int yieldState;										//YieldReturn �����Ͻ� �ش� ������Ʈ ����(���� �����Ӷ� �˻縦 ����)
	bool bLoop = false;												//�ڷ�ƾ ���� üũ(YieldReturn �����Ͻ� ���� ������ �������� �켱�� �絵)

private:
	void (T::* p_coroutineFunc)(ExecuteCoroutine*);					//T(Component)::void(ExecuteCoroutine*) �� �Լ� ������
	bool bYieldReturnDelay;											//YieldReturnDelay�� 1������ Delay
	T* p_customComponent;
	CoroutineState coroutineState;

public:
	void AddCoroutineFunc(void (T::* _pFunc)(ExecuteCoroutine*));	//������ Ŀ������ ������Ʈ���� T(Component)::void�������� �Լ� �߰� 
	void StartCoroutine();
	void YieldReturn(WaitForSecondsTimer* _time = nullptr);			//YieldReturn(nullptr)==�������� ���,YieldReturn(_time)_time��ŭ ���	
	bool ExecuteCoroutineState();											

private:
	void YieldReturnState();
	void MoveNext();
	void CheckNextState();
};

#endif 
