#pragma once
#ifndef __TEXTURE_H__
#define __TEXTURE_H__
#include "stb_image.h"
#include <glad/glad.h>
#include <iostream>

class Texture
{
public:
	Texture(const char* path, bool alpha = false);
	void BindTexture(unsigned int pos);
	unsigned int m_texture;


};

#endif // !__TEXTURE_H__



