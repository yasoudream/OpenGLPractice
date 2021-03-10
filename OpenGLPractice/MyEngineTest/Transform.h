#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/matrix.hpp>
#include <iostream>

using namespace glm;
class Transform
{
public:
	glm::mat4 GetLocalMatrix();
	glm::mat4 GetPositionMatrix();
	glm::mat4 GetRotateMatrix();
	glm::mat4 GetScaleMatrix();

	glm::vec3 m_position;
	glm::vec3 m_rotate;
	glm::vec3 m_scale;
	Transform();
	~Transform();
};

