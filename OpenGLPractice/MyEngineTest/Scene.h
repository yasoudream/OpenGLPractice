#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

#include "Node.h"
#include "LibsHeads.h"
#include "Model.h"
#include "Light.h"
#include "DirectionalLight.h"
#include "Skybox.h"

struct GLFWwindow;

class Scene final : public Node
{
public:
    static Scene* GetInstance();
    void ResetAll();
    void SceneStart(GLFWwindow* window);
    void SceneUpdate(GLFWwindow* window);
    void SceneRenderUpdate();
    bool IsLightMapDraw();
    virtual mat4x4 GetLocalMatrix() override;
    void SetLightMapDraw(bool value);
    shared_ptr<Light> m_sceneLight;
    virtual void Start() override;
    virtual void Update() override;
private:
    static unique_ptr<Scene> m_pInstance;
    shared_ptr<Skybox> m_skybox;
    bool isLightMapDraw = false;
    Scene();
    Scene(Scene&&) = delete;
    Scene(const Scene&) = delete;




};

#endif // !__SCENE_H__


