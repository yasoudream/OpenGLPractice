#pragma once
#ifndef __MODEL_H__
#define __MODEL_H__
#include "Mesh.h"
#include "Scene.h"
#include "Material.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <memory>
class Material;

class Model: public Node
{
public:
	void Draw();
	Model(const shared_ptr<Mesh>& mesh, const shared_ptr<Material>& material, shared_ptr<Node> parent = nullptr);
	shared_ptr<Model> Create();
	virtual void Update() override;
	virtual void RenderUpdate() override final;


protected:
	shared_ptr<Mesh> m_pMesh;
	shared_ptr<Material> m_pMaterial;

};


#endif // !__MODEL_H__



