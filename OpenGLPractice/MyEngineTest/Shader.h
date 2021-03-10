#pragma once
#ifndef __SHADER_H__
#define __SHADER_H__

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "MyConst.h"

using namespace std;
using namespace glm;

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	
	static void Use(const shared_ptr<Shader>& thissp);

	void SetBool(const string& name, bool value) const;
	void SetInt(const string& name, int value) const;
	void SetFloat(const string& name, float value) const;
	void SetVec2(const string& name, const vec2& value) const;
	void SetVec2(const string& name, float x, float y) const;
	void SetVec3(const string& name, const vec3& value) const;
	void SetVec3(const std::string& name, float x, float y, float z) const;
	void SetVec4(const std::string& name, const glm::vec4& value) const;
	void SetVec4(const std::string& name, float x, float y, float z, float w);
	void SetMat2(const std::string& name, const glm::mat2& mat) const;
	void SetMat3(const std::string& name, const glm::mat3& mat) const;
	void SetMat4(const std::string& name, const glm::mat4& mat) const;
	static shared_ptr<Shader> GetCurrentShader();
	static shared_ptr<Shader> GetLightMapShader();

protected:
	unsigned int m_ID;
	static shared_ptr<Shader> currentShader;
	static void CheckCompileErrors(GLuint shader, std::string type);
	static shared_ptr<Shader> lightMapShader;
};



#endif // !__SHADER_H__



