#pragma once
#ifndef __NODE_H__
#define __NODE_H__
#include "LibsHeads.h"
#include "Transform.h"
class Node
{
public:
	Node(shared_ptr<Node> parent = nullptr);
	virtual ~Node();
	virtual mat4x4 GetLocalMatrix();
	virtual mat4x4 GetRotateMatrix();
	virtual mat4x4 GetWorldMatrix();
	virtual mat4x4 GetWorldRotateMatrix();

	virtual void AddChild(shared_ptr<Node> node);
	virtual void RemoveChild(shared_ptr<Node> node);
	virtual void Start();
	virtual void Update();
	virtual void RenderUpdate();

	virtual void SetLocalPosition(vec3 position);
	virtual vec3 GetLocalPosition();
	virtual vec3 GetWorldPosition();

	virtual void SetLocalRotate(vec3 rotate);
	virtual vec3 GetLocalRotate();

	virtual void SetLocalScale(vec3 scale = vec3(1));
	virtual vec3 GetLocalScale();


protected:
	Node* m_pParent;
	list<shared_ptr<Node>> m_listChildren;
	mat4x4 m_worldMatrix;
	mat4x4 m_worldRotateMatrix;

	void SetWorldDirtyTag();
	bool m_worldDirtyTag;

	void SetRotateDirtyTag();
	bool m_rotateDirtyTag;

	Transform m_transform;
	void Start_main();
	void Update_main();
	void RenderUpdate_main();

};


#endif // !__NODE_H__



