#pragma once
#ifndef __SKYBOX_H__
#define __SKYBOX_H__
#include "Shader.h"
#include "CubeTexture.h"
#include "LibsHeads.h"
class Skybox
{
public:
	Skybox(const shared_ptr<Shader>& shader, const shared_ptr<CubeTexture>& cubetexture);
	void Draw(mat4 view, const mat4& projection);
	shared_ptr<Shader> m_shader;
	shared_ptr<CubeTexture> m_cubetexture;
	unsigned int m_VAO, m_VBO;
};

#endif // !__SKYBOX_H__



