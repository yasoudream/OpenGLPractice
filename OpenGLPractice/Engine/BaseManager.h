#pragma once
# ifndef __BASE_MANAGER_H__
# define __BASE_MANAGER_H__

#include <iostream>
#include <vector>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Singleton.h"
#include "MyConst.h"
#include "MyMouse.h"


class BaseManager : public Singleton<BaseManager>
{
public:
	FRIEND_SINGLENTON(BaseManager);
	~BaseManager();

	float screenWidth;
	float screenHeight;
	
	int Run();
	
private:
	
	//窗口相关
	GLFWwindow* glWindow;

	//输入设备
	std::unique_ptr<MyMouse> m_pMouse;
	//std::unique_ptr<MyKeyboard> m_pKeyboard;

	//方法
	bool windowInit();		//窗口初始化
	void mainLoop();		//游戏循环
};










#endif // !__BASE_MANAGER_H__

