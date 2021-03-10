#include "BaseManager.h"

bool BaseManager::windowInit()
{
	//glfw初始化
	glfwInit();//初始化
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//配置GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//配置GLFW
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	//窗口大小
	screenWidth = MyConst::SCREEN_WIDTH;
	screenHeight = MyConst::SCREEN_HEIGHT;
	//创建窗口
	glWindow = glfwCreateWindow(screenWidth, screenHeight, MyConst::WINDOW_NAME, nullptr, nullptr);
	if (glWindow == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(glWindow);
	//glEnable(GL_MULTISAMPLE);//多重采样抗锯齿
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	glfwSetInputMode(glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	float lastX = screenWidth / 2.0f;
	float lastY = screenHeight / 2.0f;
	bool firstMouse = true;

	m_pMouse = std::make_unique<MyMouse>();
	//m_pKeyboard = std::make_unique<MyKeyboard>();
	//m_pGameCamera = std::make_shared<GameCamera>();
	//m_pLightCamera = std::make_shared<LightCamera>();
	glfwSetFramebufferSizeCallback(glWindow, [](GLFWwindow* window, int width, int height) { BaseManager::getInstance()->resize_callback(window, width, height); });
	glfwSetCursorPosCallback(glWindow, [](GLFWwindow* window, double xpos, double ypos) {BaseManager::getInstance()->mouse_callback(window, xpos, ypos); });
	glfwSetScrollCallback(glWindow, [](GLFWwindow* window, double xoffset, double yoffset) {BaseManager::getInstance()->scroll_callback(window, xoffset, yoffset); });

	resize_callback(glWindow, screenWidth, screenHeight);
	glEnable(GL_DEPTH_TEST);

	m_pRenderManager = RenderManager::getInstance();
	m_pRefManager = RefManager::getInstance();
	m_pLogicManager = LogicManager::getInstance();
	m_pPhysicsManager = PhysicsManager::getInstance();
	m_pRenderManager->init();
	m_pRefManager->init();
	m_pLogicManager->init();
	m_pPhysicsManager->init();

}
