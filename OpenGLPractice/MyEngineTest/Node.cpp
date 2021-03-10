#include "Node.h"

Node::Node(shared_ptr<Node> parent)
	:m_pParent(parent.get()), m_rotateDirtyTag(true), m_worldRotateMatrix(1), m_worldDirtyTag(true), m_worldMatrix(1)
{
}

Node::~Node()
{
	m_listChildren.clear();
}

mat4x4 Node::GetLocalMatrix()
{
	return m_transform.GetLocalMatrix();
}

mat4x4 Node::GetRotateMatrix()
{
	return m_transform.GetRotateMatrix();
}

mat4x4 Node::GetWorldMatrix()
{
	if (m_worldDirtyTag)
	{
		if (m_pParent)
			m_worldMatrix = m_pParent->GetWorldMatrix() * m_transform.GetLocalMatrix();
		else
			m_worldMatrix = m_transform.GetLocalMatrix();
		m_worldDirtyTag = false;
	}
	return m_worldMatrix;
}


mat4x4 Node::GetWorldRotateMatrix()
{
	if (m_rotateDirtyTag)
	{
		if (m_pParent)
			m_worldRotateMatrix = m_pParent->GetWorldRotateMatrix() * m_transform.GetRotateMatrix();
		else
			m_worldRotateMatrix = m_transform.GetRotateMatrix();
		m_rotateDirtyTag = false;
	}
	return m_worldRotateMatrix;
}


void Node::AddChild(shared_ptr<Node> node)
{
	node->m_pParent = this;
	m_listChildren.push_back(move(node));
}

void Node::RemoveChild(shared_ptr<Node> node)
{
	m_listChildren.remove(node);
	node->m_pParent = nullptr;
}

void Node::Start()
{
}

void Node::Update()
{

}

void Node::RenderUpdate()
{
}

void Node::SetLocalPosition(vec3 position)
{
	m_transform.m_position = move(position);
	SetWorldDirtyTag();
}

vec3 Node::GetLocalPosition()
{
	return m_transform.m_position;
}

vec3 Node::GetWorldPosition()
{
	vec4 pos(0,0,0,1);
	return GetWorldMatrix() * pos;
}

void Node::SetLocalRotate(vec3 rotate)
{
	m_transform.m_rotate = move(rotate);
	SetWorldDirtyTag();
	SetRotateDirtyTag();
}

vec3 Node::GetLocalRotate()
{
	return m_transform.m_rotate;
}

void Node::SetLocalScale(vec3 scale)
{
	m_transform.m_scale = move(scale);
	SetWorldDirtyTag();
}

vec3 Node::GetLocalScale()
{
	return m_transform.m_scale;
}


void Node::Update_main()
{
	Update();
	for (auto p : m_listChildren)
	{
		p->Update_main();
	}
}

void Node::RenderUpdate_main()
{
	RenderUpdate();
	for (auto p : m_listChildren)
	{
		p->RenderUpdate_main();
	}
}


void Node::SetWorldDirtyTag()
{
	this->m_worldDirtyTag = true;
	for (auto node : m_listChildren)
	{
		node->SetWorldDirtyTag();
	}
}

void Node::SetRotateDirtyTag()
{
	this->m_rotateDirtyTag = true;
	for (auto node : m_listChildren)
	{
		node->SetRotateDirtyTag();
	}
}

void Node::Start_main()
{
	Start();
	for (auto p : m_listChildren)
	{
		p->Start_main();
	}
}
