#ifndef _TIME_H_
#define _TIME_H_
#define DELTA_TIME Time::Instance()->GetDeltaTime()
#include <windows.h>

class Time
{
private:
	Time();
	~Time() {};

public:
	static Time* Instance()
	{
		static Time instance;
		return &instance;
	}

private:
	LARGE_INTEGER frameInfo, updateCurFrame, updatePrevFrame;
	//fixed
	double fixedFrame;
	double fixedTime;
	//render
	double renderFrame;
	double renderTime;
	//delta
	double deltaTime;

public:	
	void UpdateTimer();													
	bool FixedUpdateTimer();
	bool RenderUpdateTimer();
	double GetDeltaTime();
};

#endif 