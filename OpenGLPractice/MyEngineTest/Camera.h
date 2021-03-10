#pragma once
#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Node.h"
#include "MyConst.h"
#include "Input.h"
#include "Time.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <vector>

using namespace camera_const;

class Camera : public Node
{


public:
    static Camera* GetMainCamera();
    void SetMain();
    ~Camera();

    float Zoom;

	// Default camera values
    Camera(glm::vec3 pos = glm::vec3(0), glm::vec3 rot = glm::vec3(0));

    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
    void LookAt(vec3 target);

    virtual void Update() override;
protected:
    static Camera* pMainCamera;
};

#endif // !__CAMERA_H__



