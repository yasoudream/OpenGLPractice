#include "MyKeyboard.h"

std::shared_ptr<MyKeyboard> MyKeyboard::GetInstance()
{
	if (instance == nullptr)
		instance.reset(new MyKeyboard());
	return instance;
}
void MyKeyboard::UpdateKeyPress(GLFWwindow* window)
{
	for (auto code : keyIndexs)
	{
		int index = static_cast<int>(code);
		int keystate = glfwGetKey(window, index);
		if (keystate == GLFW_PRESS)
			m_bitSet[index] = true;
		else if (keystate == GLFW_RELEASE)
			m_bitSet[index] = false;
	}
}

bool MyKeyboard::GetKeyPress(KeyCode key)
{
	if (static_cast<int>(key) >= 0 && static_cast<int>(key) <= 348)
	{
		return m_bitSet[static_cast<int>(key)];
	}
	return false;
}
MyKeyboard::MyKeyboard()
{

}
std::shared_ptr<MyKeyboard> MyKeyboard::instance(nullptr);
std::vector<KeyCode> MyKeyboard::keyIndexs
{
	KeyCode::KEY_SPACE,
	KeyCode::KEY_APOSTROPHE,
	KeyCode::KEY_COMMA,
	KeyCode::KEY_MINUS,
	KeyCode::KEY_PERIOD,
	KeyCode::KEY_SLASH,
	KeyCode::KEY_0,
	KeyCode::KEY_1,
	KeyCode::KEY_2,
	KeyCode::KEY_3,
	KeyCode::KEY_4,
	KeyCode::KEY_5,
	KeyCode::KEY_6,
	KeyCode::KEY_7,
	KeyCode::KEY_8,
	KeyCode::KEY_9,
	KeyCode::KEY_SEMICOLON,
	KeyCode::KEY_EQUAL,
	KeyCode::KEY_A,
	KeyCode::KEY_B,
	KeyCode::KEY_C,
	KeyCode::KEY_D,
	KeyCode::KEY_E,
	KeyCode::KEY_F,
	KeyCode::KEY_G,
	KeyCode::KEY_H,
	KeyCode::KEY_I,
	KeyCode::KEY_J,
	KeyCode::KEY_K,
	KeyCode::KEY_L,
	KeyCode::KEY_M,
	KeyCode::KEY_N,
	KeyCode::KEY_O,
	KeyCode::KEY_P,
	KeyCode::KEY_Q,
	KeyCode::KEY_R,
	KeyCode::KEY_S,
	KeyCode::KEY_T,
	KeyCode::KEY_U,
	KeyCode::KEY_V,
	KeyCode::KEY_W,
	KeyCode::KEY_Y,
	KeyCode::KEY_Z,
	KeyCode::KEY_LEFT_BRACKET,
	KeyCode::KEY_BACKSLASH,
	KeyCode::KEY_RIGHT_BRACKET,
	KeyCode::KEY_GRAVE_ACCENT,
	KeyCode::KEY_WORLD_1,
	KeyCode::KEY_WORLD_2,
	KeyCode::KEY_ESCAPE,
	KeyCode::KEY_ENTER,
	KeyCode::KEY_TAB,
	KeyCode::KEY_BACKSPACE,
	KeyCode::KEY_INSERT,
	KeyCode::KEY_DELETE,
	KeyCode::KEY_RIGHT,
	KeyCode::KEY_LEFT,
	KeyCode::KEY_DOWN,
	KeyCode::KEY_UP,
	KeyCode::KEY_PAGE_UP,
	KeyCode::KEY_PAGE_DOWN,
	KeyCode::KEY_HOME,
	KeyCode::KEY_END,
	KeyCode::KEY_CAPS_LOCK,
	KeyCode::KEY_SCROLL_LOCK,
	KeyCode::KEY_NUM_LOCK,
	KeyCode::KEY_PRINT_SCREEN,
	KeyCode::KEY_PAUSE,
	KeyCode::KEY_F1,
	KeyCode::KEY_F2,
	KeyCode::KEY_F3,
	KeyCode::KEY_F4,
	KeyCode::KEY_F5,
	KeyCode::KEY_F6,
	KeyCode::KEY_F7,
	KeyCode::KEY_F8,
	KeyCode::KEY_F9,
	KeyCode::KEY_F10,
	KeyCode::KEY_F11,
	KeyCode::KEY_F12,
	KeyCode::KEY_F13,
	KeyCode::KEY_F14,
	KeyCode::KEY_F15,
	KeyCode::KEY_F16,
	KeyCode::KEY_F17,
	KeyCode::KEY_F18,
	KeyCode::KEY_F19,
	KeyCode::KEY_F20,
	KeyCode::KEY_F21,
	KeyCode::KEY_F22,
	KeyCode::KEY_F23,
	KeyCode::KEY_F24,
	KeyCode::KEY_F25,
	KeyCode::KEY_KP_0,
	KeyCode::KEY_KP_1,
	KeyCode::KEY_KP_2,
	KeyCode::KEY_KP_3,
	KeyCode::KEY_KP_4,
	KeyCode::KEY_KP_5,
	KeyCode::KEY_KP_6,
	KeyCode::KEY_KP_7,
	KeyCode::KEY_KP_8,
	KeyCode::KEY_KP_9,
	KeyCode::KEY_KP_DECIMAL,
	KeyCode::KEY_KP_DIVIDE,
	KeyCode::KEY_KP_MULTIPLY,
	KeyCode::KEY_KP_SUBTRACT,
	KeyCode::KEY_KP_ADD,
	KeyCode::KEY_KP_ENTER,
	KeyCode::KEY_KP_EQUAL,
	KeyCode::KEY_LEFT_SHIFT,
	KeyCode::KEY_LEFT_CONTROL,
	KeyCode::KEY_LEFT_ALT,
	KeyCode::KEY_LEFT_SUPER,
	KeyCode::KEY_RIGHT_SHIFT,
	KeyCode::KEY_RIGHT_CONTROL,
	KeyCode::KEY_RIGHT_ALT,
	KeyCode::KEY_RIGHT_SUPER,
	KeyCode::KEY_MENU
};