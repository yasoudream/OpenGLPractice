#pragma once
#ifndef __TIME_H__
#define __TIME_H__
#include <GLFW/glfw3.h>

class Time
{
public:
	static float GetDeltaTime();
	static void TimeTrigger();

	static float GetTime();

private:
	static float m_lastFlameTime;
	static float m_thisFlameTime;
};

#endif // !__TIME_H_



