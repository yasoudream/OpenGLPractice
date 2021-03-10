#include "Scene.h"

Scene* Scene::GetInstance()
{
    if (m_pInstance == nullptr)
        m_pInstance.reset(new Scene());
    return m_pInstance.get();
}

void Scene::ResetAll()
{
    m_listChildren.clear();
}

void Scene::SceneStart(GLFWwindow* window)
{
    Start_main();
}

void Scene::SceneUpdate(GLFWwindow* window)
{
    if (MyKeyboard::GetInstance()->GetKeyPress(KeyCode::KEY_ESCAPE))
        glfwSetWindowShouldClose(window, true);
    Update_main();
}


void Scene::SceneRenderUpdate()
{
	//阴影
    //glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SetLightMapDraw(true);
	glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
	glBindFramebuffer(GL_FRAMEBUFFER, Light::depthMapFBO);
	glClear(GL_DEPTH_BUFFER_BIT);
	glCullFace(GL_FRONT);
	Material::UseLightMapMaterial();
	Material::lightMapMaterial->GetShader()->SetMat4("lightSpaceMatrix", Light::currentLight->GetLightMatrix());

	RenderUpdate_main();

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	// 2. 像往常一样渲染场景，但这次使用深度贴图
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glCullFace(GL_BACK);
	SetLightMapDraw(false);
	m_skybox->Draw(Camera::GetMainCamera()->GetViewMatrix(), Camera::GetMainCamera()->GetProjectionMatrix());

	RenderUpdate_main();
}

bool Scene::IsLightMapDraw()
{
	return isLightMapDraw;
}

mat4x4 Scene::GetLocalMatrix()
{
	return mat4x4(1);
}

void Scene::SetLightMapDraw(bool value)
{
	isLightMapDraw = value;
}

void Scene::Start()
{
    shared_ptr<Shader> shader(new Shader(PATH("WithShadow.vert"),
        PATH("WithShadow.frag")));

    auto cubeMesh = Mesh::GetCube();
    auto planeMesh = Mesh::GetPlane();

    shared_ptr<Camera> camera(new Camera(vec3(0, 4.5 * 2, 7 * 2), vec3(30, 180, 0)));

    shared_ptr<Texture> texture(new Texture(PATH("863615407.jpg")));
    shared_ptr<Texture> texture2(new Texture(PATH("container.jpg")));

    shared_ptr<Material> material(new Material(shader));
    shared_ptr<Material> material2(new Material(shader));

    material->AddTexture(texture, 1);
    material2->AddTexture(texture2, 1);

    shared_ptr<Model> cubemodel_0(new Model(cubeMesh, material));
    vector<shared_ptr<Model>> cubeVec(4);
    for (auto& p : cubeVec)
        p = cubemodel_0->Create();

    shared_ptr<Model> planemodel(new Model(planeMesh, material2));


    shared_ptr<Node> car(new Node());
    Scene::GetInstance()->AddChild(camera);
    Scene::GetInstance()->AddChild(planemodel);
    Scene::GetInstance()->AddChild(cubemodel_0);
    Scene::GetInstance()->AddChild(car);
    car->AddChild(cubemodel_0);
    for (auto pt : cubeVec)
        car->AddChild(pt);

    car->SetLocalPosition(vec3(0, 1.4f, 0));

    cubeVec[0]->SetLocalPosition(vec3(-1, -1.5, -1));
    cubeVec[1]->SetLocalPosition(vec3(1, -1.5, -1));
    cubeVec[2]->SetLocalPosition(vec3(-1, -1.5, 1));
    cubeVec[3]->SetLocalPosition(vec3(1, -1.5, 1));
    //for (auto pt : cubeVec)
    //    pt->SetLocalScale(vec3(1, 1, 1));
    //cubemodel->AddChild(camera);


    planemodel->SetLocalPosition(vec3(0.0f, -3.0f, 0.0f));
    planemodel->SetLocalScale(vec3(15, 15, 15));


    cubemodel_0->SetLocalPosition(vec3(0.0f, 1.0f, 0.0f));
    cubemodel_0->SetLocalScale(vec3(4, 2, 2));



    //天空盒
    vector<string> skyfaces
    {
        PATH("skybox_right.jpg"),
        PATH("skybox_left.jpg"),
        PATH("skybox_top.jpg"),
        PATH("skybox_bottom.jpg"),
        PATH("skybox_front.jpg"),
        PATH("skybox_back.jpg")
    };
    shared_ptr<CubeTexture> cubeTexture(new CubeTexture(skyfaces));
    shared_ptr<Shader> skyshader(new Shader(PATH("Skybox.vert"), PATH("Skybox.frag")));
    shared_ptr<Skybox> skybox(new Skybox(skyshader, cubeTexture));
    m_skybox = skybox;
}

void Scene::Update()
{

}

unique_ptr<Scene> Scene::m_pInstance(nullptr);

Scene::Scene():m_sceneLight(new DirectionalLight(vec3(0,7,3.5f), vec3(0.3, -1, -0.5)))
{

}

