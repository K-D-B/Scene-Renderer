#include"RenderScene.h"
#include"../object/Terrain.h"
#include"../component/GameObject.h"
#include"../object/SkyBox.h"
#include"../component/Lights.h"

std::shared_ptr<RenderScene> RenderScene::addObject(std::shared_ptr<GameObject> object) {
	objects.push_back(object);
	if (object->GetComponent("Light")) {
		std::shared_ptr<Light> light = std::dynamic_pointer_cast<Light> (object->GetComponent("Light"));
		switch (light->type)
		{
		case LightType::POINT:
			this->pointLights.push_back(light);
			break;
		case LightType::DIRECTIONAL:
			this->directionLights.push_back(light);
			break;
		default:
			break;
		}
	}
	return shared_from_this();
}
std::shared_ptr<RenderScene> RenderScene::addTerrain(std::shared_ptr<Terrain>terrain) {
	this->terrain = terrain;
	return shared_from_this();
}
std::shared_ptr<RenderScene> RenderScene::addSkyBox(std::shared_ptr<SkyBox>skybox) {
	this->skybox = skybox;
	return shared_from_this();
}
//std::shared_ptr<RenderScene> RenderScene::addLight(std::shared_ptr<Light> light) {
	//lights.push_back(light);
	//return shared_from_this();
//}
