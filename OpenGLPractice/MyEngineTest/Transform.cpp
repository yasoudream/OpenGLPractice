#include "Transform.h"

glm::mat4 Transform::GetLocalMatrix()
{
	mat4 trans = mat4(1.0f);
	mat4 t = translate(trans, m_position);		//位移

	//qua<float> q = glm::qua<float>(glm::radians(m_rotate));		//旋转
	//mat4 r = glm::mat4_cast(q) * mat4(1);
	mat4 r = GetRotateMatrix();

	mat4 s = scale(mat4(1), m_scale);				//缩放
	
	return t * r * s;
}

glm::mat4 Transform::GetPositionMatrix()
{
	return translate(mat4(1), m_position);
}

glm::mat4 Transform::GetRotateMatrix()
{
	qua<float> q = glm::qua<float>(glm::radians(m_rotate));		//旋转
	return glm::mat4_cast(q);
	//mat4 rot(1);
	//rot = rotate(rot, radians(m_rotate.x), vec3(1, 0, 0));
	//rot = rotate(rot, radians(m_rotate.y), vec3(0, 1, 0));
	//rot = rotate(rot, radians(m_rotate.z), vec3(0, 0, 1));
	
	
	//return rot;
}

glm::mat4 Transform::GetScaleMatrix()
{
	return scale(mat4(1), m_scale);
}

Transform::Transform():m_position(0), m_rotate(0), m_scale(1)
{
}

Transform::~Transform()
{
}
