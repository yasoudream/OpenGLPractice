#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(vec3 pos, vec3 dir): lightDir(move(dir))
{
    lightPos = pos;
    if (Light::currentLight == nullptr)
        currentLight = this;
}

DirectionalLight::~DirectionalLight()
{
    if (currentLight == this)
        currentLight = nullptr;
}

mat4 DirectionalLight::GetLightMatrix()
{
    GLfloat near_plane = 0.1f, far_plane = 30.0f;
    glm::mat4 lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
    glm::mat4 lightView = glm::lookAt(lightPos, lightPos + lightDir, glm::vec3(0.0f, 1.0f, 0.0f));
    return lightProjection * lightView;
}
