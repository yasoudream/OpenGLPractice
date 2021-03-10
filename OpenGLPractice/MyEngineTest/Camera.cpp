#include "Camera.h"
Camera* Camera::GetMainCamera()
{
    return pMainCamera;
}

void Camera::SetMain()
{
    pMainCamera = this;
}

Camera::~Camera()
{
    if (pMainCamera == this)
        pMainCamera = nullptr;
}

Camera* Camera::pMainCamera(nullptr);



Camera::Camera(glm::vec3 pos, glm::vec3 rot):Zoom(ZOOM)
{
    SetLocalPosition(pos);
    SetLocalRotate(rot);
    if (!pMainCamera)
        pMainCamera = this;
}

glm::mat4 Camera::GetViewMatrix()
{
    vec3 pos = GetWorldPosition();
    mat4 axs{{1,0,0,0},{0,1,0,0},{0,0,1,0}, {0,0,0,0} };
    axs = GetWorldRotateMatrix() * axs;
    vec3 front = axs[2];
    vec3 up = axs[1];
    return glm::lookAt(pos, pos + front, up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
    return glm::perspective(glm::radians(Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
}

void Camera::LookAt(vec3 target)
{

}

void Camera::Update()
{
    //鼠标控制
    auto mouse = MyMouse::GetInstance();
    auto&& state = mouse->GetState();
    auto&& rot = GetLocalRotate();
    rot.y += state.offsetX * ROTATE_RATE_X;
    rot.x -= state.offsetY * ROTATE_RATE_Y;
    rot.x = std::min(rot.x, 90.0f);
    rot.x = std::max(rot.x, -90.0f);
    SetLocalRotate(rot);

    //计算前方
    mat4 vecs = GetWorldRotateMatrix();
    
    vec3 right = normalize(vecs[0]);
    vec3 up = normalize(vecs[1]);
    vec3 front = normalize(vecs[2]);

    //键盘控制
    auto keyboard = MyKeyboard::GetInstance();
    auto&& pos = GetLocalPosition();
    if (keyboard->GetKeyPress(KeyCode::KEY_W))
        pos += front * MOVE_SPEED * Time::GetDeltaTime();
    if (keyboard->GetKeyPress(KeyCode::KEY_S))
        pos -= front * MOVE_SPEED * Time::GetDeltaTime();
    if (keyboard->GetKeyPress(KeyCode::KEY_A))
        pos += right * MOVE_SPEED * Time::GetDeltaTime();
    if (keyboard->GetKeyPress(KeyCode::KEY_D))
        pos -= right * MOVE_SPEED * Time::GetDeltaTime();
    if (keyboard->GetKeyPress(KeyCode::KEY_SPACE))
        pos += up * MOVE_SPEED * Time::GetDeltaTime();
    if (keyboard->GetKeyPress(KeyCode::KEY_LEFT_CONTROL))
        pos -= up * MOVE_SPEED * Time::GetDeltaTime();
    SetLocalPosition(pos);
}
