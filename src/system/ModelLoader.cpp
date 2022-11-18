#include"ModelLoader.h"
#include"../renderer/RenderScene.h"
#include"../component/GameObject.h"
#include"../object/SkyBox.h"
#include<utility>

ModelLoader::ModelLoader() {

}

ModelLoader::~ModelLoader() {
	for (auto& t : threadpool) {
		t.join();
	}
}
void ModelLoader::loadObjectAsync(std::shared_ptr<RenderScene>& scene, const std::string& filename) {
	std::thread loadThread = std::thread(&ModelLoader::loadObject, this, scene, filename);
	threadpool.push_back(std::move(loadThread));
}

void ModelLoader::loadObject(std::shared_ptr<RenderScene>& scene, const std::string& filename) {
	std::ifstream f(filename);
	json data = json::parse(f);
	std::shared_ptr<GameObject> object = std::make_shared<GameObject>();
	object->loadFromJson(data);
	//mtx.lock();
	scene->addObject(object);
}

void ModelLoader::loadSceneAsync(std::shared_ptr<RenderScene>& scene, const std::string& filename) {
	std::ifstream f(filename);
	json data = json::parse(f);
	if (data.find("objects") != data.end()) {
		auto objects = data["objects"];
		for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
			std::string path = iter.value().get<std::string>();
			this->loadObjectAsync(scene, path);
		}
	}
	if (data.find("sky") != data.end()) {
		std::string path = data["sky"].get<std::string>();
		this->loadSkyAsync(scene, path);
	}
}

void ModelLoader::loadSkyAsync(std::shared_ptr<RenderScene>& scene, const std::string& filename) {
	std::thread loadThread = std::thread(&ModelLoader::loadSky, this, scene, filename);
	threadpool.push_back(std::move(loadThread));
}

void ModelLoader::loadSky(std::shared_ptr<RenderScene>& scene, const std::string& filename) {
	std::shared_ptr<Sky> sky = std::make_shared<Sky>();
	//scene->addObject(atm);
	scene->addSky(sky);
}
