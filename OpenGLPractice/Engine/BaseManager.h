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
	
	//�������
	GLFWwindow* glWindow;

	//�����豸
	std::unique_ptr<MyMouse> m_pMouse;
	//std::unique_ptr<MyKeyboard> m_pKeyboard;

	//����
	bool windowInit();		//���ڳ�ʼ��
	void mainLoop();		//��Ϸѭ��
};










#endif // !__BASE_MANAGER_H__

