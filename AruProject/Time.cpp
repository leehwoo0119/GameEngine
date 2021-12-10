#include "Time.h"

Time::Time() : fixedFrame(0.0f), deltaTime(0.0f), fixedTime(0.0f), renderFrame(0.0f), renderTime(0.0f)
{
    QueryPerformanceFrequency(&frameInfo);
    QueryPerformanceCounter(&updateCurFrame);
    QueryPerformanceCounter(&updatePrevFrame);
    fixedFrame = 1.0f / 50.0f;
    renderFrame = 1.0f / 60.0;
}

void Time::UpdateTimer()
{
    QueryPerformanceCounter(&updateCurFrame);
    deltaTime = (updateCurFrame.QuadPart - updatePrevFrame.QuadPart) / (double)frameInfo.QuadPart;
    updatePrevFrame = updateCurFrame;
}

bool Time::FixedUpdateTimer()
{
    fixedTime += deltaTime;

    if (fixedFrame <= fixedTime)
    {
        fixedTime = 0;
        return true;
    }
    return false;
}

bool Time::RenderUpdateTimer()
{
    renderTime += deltaTime;

    if (renderFrame <= renderTime)
    {
        renderTime = 0;
        return true;
    }
    return false;
}

double Time::GetDeltaTime()
{
    return deltaTime;
}
