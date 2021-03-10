#pragma once
#ifndef __MESH_H__
#define __MESH_H__
#include "LibsHeads.h"
#include "Node.h"

struct Vertex
{
	vec3 position;
	vec3 normal;
	vec2 texcoords;
};

class Mesh
{
public:
	Mesh(vector<Vertex> vertices, vector<unsigned int> indices);
	void DrawWithCurrentShader();
	static shared_ptr<Mesh> GetCube();
	static shared_ptr<Mesh> GetPlane();
protected:
	vector<Vertex> m_vertices;
	vector<unsigned int> m_indices;
	unsigned int m_VAO, m_VBO, m_EBO;
	void SetupMesh();

private:
	static shared_ptr<Mesh> mesh_Cube;
	static shared_ptr<Mesh> mesh_Plane;
};

#endif // !__MESH_H__



