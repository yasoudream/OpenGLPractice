#pragma once
#ifndef __DIRECTIONAL_LIGHT_H__
#define __DIRECTIONAL_LIGHT_H__
#include "Light.h"
#include "LibsHeads.h"
using namespace glm;

class DirectionalLight : public Light
{
public:
	DirectionalLight(vec3 pos, vec3 dir);
	~DirectionalLight();
	vec3 lightDir;
	virtual mat4 GetLightMatrix() override;

};

#endif