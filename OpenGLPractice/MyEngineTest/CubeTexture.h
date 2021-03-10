#pragma once
#ifndef __CUBE_TEXTURE__
#define __CUBE_TEXTURE__
#include "stb_image.h"
#include <glad/glad.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CubeTexture
{
public:
	CubeTexture(vector<string> pathvec, bool alpha = false);
	void BindTexture();
	unsigned int m_texture;
};



#endif // !__CUBE_TEXTURE__



