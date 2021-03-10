#pragma once
#ifndef __MY_MOUSE_H__
#define __MY_MOUSE_H__
#include <GLFW/glfw3.h>
#include <memory>
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
	
	void processMessage(GLFWwindow* window, double xpos, double ypos);
	void processMouseScroll(GLFWwindow* window, double xpos, double ypos);
	State GetState();
	static std::shared_ptr<MyMouse> GetInstance();
	static void ScrollCallback(GLFWwindow* window, double xpos, double ypos);
	static void MessageCallback(GLFWwindow* window, double xpos, double ypos);

private:
	MyMouse();
	MyMouse& operator=(const MyMouse&) = delete;
	MyMouse& operator=(MyMouse&&) = delete;
	MyMouse(const MyMouse&) = delete;
	MyMouse(MyMouse&&) = delete;
	State m_State;
	bool m_IsFirstMouse;
	static std::shared_ptr<MyMouse> instance;
};

#endif // !__MY_MOUSE_H__



