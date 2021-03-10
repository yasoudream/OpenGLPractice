#include "Model.h"

void Model::Draw()
{
	if (Scene::GetInstance()->IsLightMapDraw())
	{	
		Shader::GetCurrentShader()->SetMat4("lightSpaceMatrix", Scene::GetInstance()->m_sceneLight->GetLightMatrix());
		Shader::GetLightMapShader()->SetMat4("model", GetWorldMatrix());
	}
	else
	{
		m_pMaterial->Use();
		Shader::GetCurrentShader()->SetMat4("model", GetWorldMatrix());
		Shader::GetCurrentShader()->SetMat4("view", Camera::GetMainCamera()->GetViewMatrix());
		Shader::GetCurrentShader()->SetMat4("projection", Camera::GetMainCamera()->GetProjectionMatrix());
		Shader::GetCurrentShader()->SetMat4("lightSpaceMatrix", Scene::GetInstance()->m_sceneLight->GetLightMatrix());
		Shader::GetCurrentShader()->SetVec3("lightPos", Scene::GetInstance()->m_sceneLight->lightPos);
		Shader::GetCurrentShader()->SetVec3("viewPos", Camera::GetMainCamera()->GetWorldPosition());
	}
	

	m_pMesh->DrawWithCurrentShader();
}

Model::Model(const shared_ptr<Mesh>& mesh, const shared_ptr<Material>& material, shared_ptr<Node> parent)
	:m_pMesh(mesh), m_pMaterial(material), Node(parent)
{

}

shared_ptr<Model> Model::Create()
{
	shared_ptr<Model> pt(new Model(this->m_pMesh, this->m_pMaterial));
	//pt->m_transform = this->m_transform;
	return pt;
}

void Model::Update()
{
	
}

void Model::RenderUpdate()
{
	Draw();
}
