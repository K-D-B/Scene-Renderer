#pragma once
#include<memory>
#include<string>
#include<vector>

class GameObject;
class Terrain; 
class SkyBox;
class Light;
class Camera;

class RenderScene : std::enable_shared_from_this<RenderScene> {
	// scene objects
public:
	std::shared_ptr<Terrain> terrain; 
	std::vector<std::shared_ptr<GameObject>> objects;
	std::shared_ptr<SkyBox> skybox; 
	std::vector<std::shared_ptr<Light>> directionLights;
	std::vector<std::shared_ptr<Light>> pointLights;

	std::shared_ptr<Camera> main_camera;

public:
	std::shared_ptr<RenderScene> addObject(std::shared_ptr<GameObject> object);
	std::shared_ptr<RenderScene> addTerrain(std::shared_ptr<Terrain>terrain);
	std::shared_ptr<RenderScene> addSkyBox(std::shared_ptr<SkyBox>skybox);
	//std::shared_ptr<RenderScene> addLight(std::shared_ptr<Light> light);
};

//namespace RenderPass {
//
//	void shadowPass(std::shared_ptr<RenderScene> scene);
//	void forwardPass(std::shared_ptr<RenderScene> scene);
//	void deferredPass(std::shared_ptr<RenderScene> scene);
//};