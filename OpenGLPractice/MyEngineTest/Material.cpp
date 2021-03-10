#include "Material.h"

Material::Material(const shared_ptr<Shader>& shader):m_pShader(shader)
{

}

shared_ptr<Material> Material::lightMapMaterial(nullptr);

Shader* Material::GetShader() const
{
	return m_pShader.get();
}

void Material::AddTexture(const shared_ptr<Texture>& texture, int pos)
{
	m_listTexture.push_back({ texture, pos });
}

void Material::ChangeTexture(const shared_ptr<Texture>& texture, int pos)
{
	bool tag = false;
	for (auto& p : m_listTexture)
	{
		if (p.second = pos)
		{
			p.first = texture;
			tag = true;
		}	
	}
	if (!tag)
	{
		AddTexture(texture, pos);
	}
}


void Material::Use()
{
	Shader::Use(m_pShader);
	m_pShader->SetInt("shadowMap", 0);
	m_pShader->SetInt("diffuseTexture", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Light::depthMap);
	for (auto p : m_listTexture)
	{
		p.first->BindTexture(p.second);
	}
	//for (auto p : m_valueMapFloat)
	//{
	//	m_pShader->SetFloat(p.first, p.second);
	//}
	//for (auto p : m_valueMapVec3)
	//{
	//	m_pShader->SetVec3(p.first, p.second);
	//}

}

void Material::AddValueVec3(string key, vec3 value)
{
	m_valueMapVec3[key] = value;
}

void Material::AddValueFloat(string key, float value)
{
	m_valueMapFloat[key] = value;
}

void Material::UseLightMapMaterial()
{
	if (lightMapMaterial == nullptr)
	{
		lightMapMaterial.reset(new Material(Shader::GetLightMapShader()));
	}
	Shader::Use(lightMapMaterial->m_pShader);
}
