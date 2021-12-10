#ifndef _SKYSCROLL_H_
#define _SKYSCROLL_H_

#include "MonoBehaviour.h"

template<typename T> class ExecuteCoroutine;
class WaitForSecondsTimer;

class SkyScroll : public MonoBehaviour
{
public:
	SkyScroll();
	virtual ~SkyScroll();

private:
	ExecuteCoroutine<SkyScroll>* p_ScrollCoroutine;
	WaitForSecondsTimer* p_WaitTime_1;
	float scrollSpeed;

public:
	void Start()override;
	void Update()override;
	void Coroutine()override;

	void ScrollCoroutine(ExecuteCoroutine<SkyScroll>* _coroutine);
};

#endif 