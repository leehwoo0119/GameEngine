#ifndef _WAITFORSECONDSTIMER_H_
#define _WAITFORSECONDSTIMER_H_

class WaitForSecondsTimer
{
public:
	WaitForSecondsTimer(double _waitTime) : coroutineFrame(_waitTime), coroutineTime(0), bWait(false) {}
	~WaitForSecondsTimer() {}

private:
	double coroutineFrame;
	double coroutineTime;
	bool bWait;

public:
	bool CoroutineUpdateTimer();
	void SetWait();
};

#endif 