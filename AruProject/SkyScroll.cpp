#include "SkyScroll.h"
#include "GameObject.h"
#include "Transform.h"
#include "Time.h"
#include "ExecuteCoroutine.cpp"

SkyScroll::SkyScroll()
{
	p_ScrollCoroutine = new ExecuteCoroutine<SkyScroll>(this);
	p_WaitTime_1 = new WaitForSecondsTimer(4.0);
	scrollSpeed = 0.5f;
}

void SkyScroll::ScrollCoroutine(ExecuteCoroutine<SkyScroll>* _coroutine)
{
	if (!_coroutine)return;
	while (_coroutine->bLoop)
	{
		_coroutine->YieldReturn(p_WaitTime_1);//p_WaitTime_1만큼 대기	
		if (_coroutine->ExecuteCoroutineState())
		{
			float curX = p_GameObject->p_Transform->position.x;
			float curY = p_GameObject->p_Transform->position.y;
			p_GameObject->p_Transform->SetPostion(Vector3(curX + 2.0, curY, 0.0f));
		}
	}
}

SkyScroll::~SkyScroll()
{
}

void SkyScroll::Start()
{
	p_ScrollCoroutine->AddCoroutineFunc(&SkyScroll::ScrollCoroutine);
}

void SkyScroll::Update()
{
	p_GameObject->p_Transform->Translate(Vector3(-scrollSpeed * DELTA_TIME, 0.0f, 0.0f));		
}

void SkyScroll::Coroutine()
{
	if (p_WaitTime_1)
	{
		if (p_WaitTime_1->CoroutineUpdateTimer())
			p_ScrollCoroutine->StartCoroutine();
	}
}
