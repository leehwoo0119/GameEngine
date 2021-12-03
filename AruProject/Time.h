#ifndef _TIME_H_
#define _TIME_H_
#include <windows.h>

class Time
{
public:
	Time();
	~Time() {};

public:
	static Time& getInstance()
	{
		static Time instance;
		return instance;
	}

public:
	LARGE_INTEGER FrameInfo, CurFrame, PrevFrame;
	int FixedUpdateCnt, deltaTimeCnt;
	double Frame;

public:
	void StartTimer();
};

#endif 