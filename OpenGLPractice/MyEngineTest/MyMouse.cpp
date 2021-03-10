#include "MyMouse.h"

MyMouse::MyMouse() :
	m_State({ 0, 0, 0, 0, 0, 0, 0.0f }),
	m_IsFirstMouse(true)
{

}

void MyMouse::processMessage(GLFWwindow* window, double xpos, double ypos)
{
	//第一次移入鼠标的特殊处理
	if (m_IsFirstMouse)
	{
		m_State.x = xpos;
		m_State.y = ypos;
		m_IsFirstMouse = false;
	}
	m_State.lastX = m_State.x;
	m_State.lastY = m_State.y;
	m_State.offsetX = m_State.lastX - xpos;
	m_State.offsetY = m_State.lastY - ypos; // reversed since y-coordinates go from bottom to top

	m_State.x = xpos;
	m_State.y = ypos;
}

void MyMouse::processMouseScroll(GLFWwindow* window, double xpos, double ypos)
{
	m_State.scroll = ypos;
}

MyMouse::State MyMouse::GetState()
{
	MyMouse::State result = m_State;
	// 重置偏移值
	m_State.offsetX = 0;
	m_State.offsetY = 0;
	m_State.scroll = 0;
	return result;
}

std::shared_ptr<MyMouse> MyMouse::GetInstance()
{
	if (instance == nullptr)
	{
		instance.reset(new MyMouse());
	}
	return instance;
}

void MyMouse::ScrollCallback(GLFWwindow* window, double xpos, double ypos)
{
	GetInstance()->processMouseScroll(window, xpos, ypos);
}

void MyMouse::MessageCallback(GLFWwindow* window, double xpos, double ypos)
{
	GetInstance()->processMessage(window, xpos, ypos);
}

std::shared_ptr<MyMouse> MyMouse::instance(nullptr);