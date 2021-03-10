#pragma once
#ifndef __MATERIAL_H__
#define __MATERIAL_H__
#include "Shader.h"
#include "Texture.h"
#include "LibsHeads.h"
#include "Light.h"

class Material
{
public:
	Material(const shared_ptr<Shader>& shader);
	Shader* GetShader() const;
	void AddTexture(const shared_ptr<Texture>& texture, int pos);
	void ChangeTexture(const shared_ptr<Texture>& texture, int pos);
	void Use();
	void AddValueVec3(string key, vec3 value);
	void AddValueFloat(string key, float value);
	static void UseLightMapMaterial();
	static shared_ptr<Material> lightMapMaterial;

protected:
	shared_ptr<Shader> m_pShader;
	list<pair<shared_ptr<Texture>, int>> m_listTexture;
	unordered_map<string, vec3> m_valueMapVec3;
	unordered_map<string, float> m_valueMapFloat;

	


};

#endif // !__MATERIAL_H_



