#pragma once
#define PATH(path) "D:\\WhiteDocuments\\Codes\\c++\\OpenGLPractice\\OpenGLPractice\\MyEngineTest\\"##path

constexpr unsigned int SCR_WIDTH = 1600;
constexpr unsigned int SCR_HEIGHT = 900;
constexpr unsigned int SHADOW_WIDTH = 500;
constexpr unsigned int SHADOW_HEIGHT = 500;

namespace camera_const
{
	constexpr float MOVE_SPEED = 2.5f;
	constexpr float ZOOM = 45.0f;
	constexpr float ROTATE_RATE_X = 0.1f;
	constexpr float ROTATE_RATE_Y = 0.1f;
}
