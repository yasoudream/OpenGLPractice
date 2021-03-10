#pragma once
#ifndef __MY_MOUSE_H__
#define __MY_MOUSE_H__

#include <GLFW/glfw3.h>


class MyMouse
{
public:
	struct State
	{
		int x;
		int y;
		int offsetX;
		int offsetY;
		int lastX;
		int lastY;
		float scroll;
	};

	MyMouse();
	void processMessage(GLFWwindow* window, double xpos, double ypos);
	void processMouseScroll(GLFWwindow* window, double xpos, double ypos);
	State getState();


	//Ä¬ÈÏ·½·¨
	MyMouse& operator=(const MyMouse&) = delete;
	MyMouse& operator=(MyMouse&&) = default;
	MyMouse(const MyMouse&) = delete;
	MyMouse(MyMouse&&) = default;

private:
	State m_State;
	bool m_IsFirstMouse;
};




#endif // !__MY_MOUSE_H__
