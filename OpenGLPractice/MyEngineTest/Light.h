#pragma once
#ifndef __LIGHT_H__
#define __LIGHT_H__
#include "LibsHeads.h"
#include "MyConst.h"
using namespace glm;
class Light
{
public:
	Light();
	~Light() {};
	vec3 lightPos;
	virtual mat4 GetLightMatrix();
	static Light* currentLight;
	static unsigned int depthMapFBO;
	static unsigned int depthMap;

};


#endif // !__LIGHT_H__


