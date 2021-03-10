#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices)
	:m_vertices(move(vertices)), m_indices(move(indices)) ,m_VAO(0), m_VBO(0), m_EBO(0)
{
    SetupMesh();
}

void Mesh::SetupMesh()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_DYNAMIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_DYNAMIC_DRAW);

    // set the vertex attribute pointers
// vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texcoords));
    
    glBindVertexArray(0);
}

void Mesh::DrawWithCurrentShader()
{
    glBindVertexArray(m_VAO);
    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

shared_ptr<Mesh> Mesh::GetCube()
{
    if (mesh_Cube == nullptr)
    {
        vector<Vertex> vers(24);
        vector<unsigned int> indexs(36);

        vers[0] = { {0.5f, 0.5f, 0.5f},{0, 0, 1},{1, 1} };
        vers[1] = { {0.5f, -0.5f, 0.5f},{0, 0, 1},{1, 0} };
        vers[2] = { {-0.5f, -0.5f, 0.5f},{0, 0, 1},{0, 0} };
        vers[3] = { {-0.5f, 0.5f, 0.5f},{0, 0, 1},{0, 1} };

        vers[4] = { {0.5f, 0.5f, -0.5f},{1, 0, 0},{1, 1} };
        vers[5] = { {0.5f, -0.5f, -0.5f},{1, 0, 0},{1, 0} };
        vers[6] = { {0.5f, -0.5f, 0.5f},{1, 0, 0},{0, 0} };
        vers[7] = { {0.5f, 0.5f, 0.5f},{1, 0, 0},{0, 1} };

        vers[8] = { {-0.5f, 0.5f, -0.5f},{0, 0, -1},{1, 1} };
        vers[9] = { {-0.5f, -0.5f, -0.5f},{0, 0, -1},{1, 0} };
        vers[10] = { {0.5f, -0.5f, -0.5f},{0, 0, -1},{0, 0} };
        vers[11] = { {0.5f, 0.5f, -0.5f},{0, 0, -1},{0, 1} };

        vers[12] = { {-0.5f, 0.5f, 0.5f},{-1, 0, 0},{1, 1} };
        vers[13] = { {-0.5f, -0.5f, 0.5f},{-1, 0, 0},{1, 0} };
        vers[14] = { {-0.5f, -0.5f, -0.5f},{-1, 0, 0},{0, 0} };
        vers[15] = { {-0.5f, 0.5f, -0.5f},{-1, 0, 0},{0, 1} };

        vers[16] = { {0.5f, 0.5f, -0.5f},{0, 1, 0},{1, 1} };
        vers[17] = { {0.5f, 0.5f, 0.5f},{0, 1, 0},{1, 0} };
        vers[18] = { {-0.5f, 0.5f, 0.5f},{0, 1, 0},{0, 0} };
        vers[19] = { {-0.5f, 0.5f, -0.5f},{0, 1, 0},{0, 1} };

        vers[20] = { {-0.5f, -0.5f, 0.5f},{0, -1, 0},{1, 1} };
        vers[21] = { {0.5f, -0.5f, 0.5f},{0, -1, 0},{1, 0} };
        vers[22] = { {0.5f, -0.5f, -0.5f},{0, -1, 0},{0, 0} };
        vers[23] = { {-0.5f, -0.5f, -0.5f},{0, -1, 0},{0, 1} };

        indexs[0] = 0; indexs[1] = 2; indexs[2] = 1; indexs[3] = 0; indexs[4] = 3; indexs[5] = 2;
        for (unsigned int i = 1; i < 6; ++i)
            for (unsigned int j = 0; j < 6; ++j)
                indexs[i * 6 + j] = indexs[j] + i * 4;

        mesh_Cube.reset(new Mesh(move(vers), move(indexs)));
    }

    
    return mesh_Cube;
}

shared_ptr<Mesh> Mesh::GetPlane()
{
    if (mesh_Plane == nullptr)
    {
        vector<Vertex> vers(4);
        vector<unsigned int> indexs(6);
        vers[0] = { {0.5f, 0, -0.5f},{0, 1, 0},{1, 1} };
        vers[1] = { {-0.5f, 0, -0.5f},{0, 1, 0},{0, 1} };
        vers[2] = { {-0.5f, 0, 0.5f},{0, 1, 0},{0, 0} };
        vers[3] = { {0.5f, 0, 0.5f},{0, 1, 0},{1, 0} };
        indexs[0] = 0; indexs[1] = 1; indexs[2] = 2; indexs[3] = 0; indexs[4] = 2; indexs[5] = 3;
        mesh_Plane.reset(new Mesh(move(vers), move(indexs)));
    }
    return mesh_Plane;
}

shared_ptr<Mesh> Mesh::mesh_Cube(nullptr);
shared_ptr<Mesh> Mesh::mesh_Plane(nullptr);