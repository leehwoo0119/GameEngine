#include "WaitForSecondsTimer.h"
#include "Time.h"

bool WaitForSecondsTimer::CoroutineUpdateTimer()
{
	if (!bWait)return true;
	coroutineTime += DELTA_TIME;

	if (coroutineFrame <= coroutineTime)
	{
		bWait = false;
		coroutineTime = 0;
		return true;
	}
	return false;
}

void WaitForSecondsTimer::SetWait()
{
	if (!bWait)bWait = true;
}
