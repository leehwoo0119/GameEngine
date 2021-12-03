#include "Time.h"

Time::Time() : FixedUpdateCnt(0), deltaTimeCnt(0)
{
    QueryPerformanceFrequency(&FrameInfo);
    QueryPerformanceCounter(&PrevFrame);
    Frame = FrameInfo.QuadPart / 60.0f;
}

void Time::StartTimer()
{
    QueryPerformanceCounter(&CurFrame);
    double TimeDis = (CurFrame.QuadPart - PrevFrame.QuadPart);

    if (TimeDis > Frame)
    {
        deltaTimeCnt++;
        PrevFrame = CurFrame;
    }
    if (deltaTimeCnt == 60)
    {
        FixedUpdateCnt++;
        deltaTimeCnt = 0;
    }
}
