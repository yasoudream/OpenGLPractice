#include "Time.h"

float Time::GetDeltaTime()
{
    return m_thisFlameTime - m_lastFlameTime;
}

void Time::TimeTrigger()
{
    m_lastFlameTime = m_thisFlameTime;
    m_thisFlameTime = glfwGetTime();
}

float Time::GetTime()
{
    return m_thisFlameTime;
}

float Time::m_lastFlameTime = 0;
float Time::m_thisFlameTime = 1.0f/60;
