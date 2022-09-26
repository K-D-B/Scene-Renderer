#pragma once
#include<memory>
#include<glm/glm.hpp>
// #include<glfw/glfw3.h>
#include"../component/Component.h"
#include<shader/Shader.h>
#include"../system/RenderManager.h"
#include<rttr/registration.h>

class Material; 
class MeshFilter; 
class Texture; 

extern RenderManager renderManager;

class MeshRenderer :public Component {
public:

	MeshRenderer();
	~MeshRenderer();

	void render(); 

	//void setShader(std::shared_ptr<Shader> shader) { this->shader = shader; };
	void setShader(ShaderType type);
	void setMaterial(std::shared_ptr<Material> material) { material = material; };
	void setView(glm::mat4 view) { view = view; };
	void setProjection(glm::mat4 projection) { projection = projection; };
	void setDrawMode(GLenum drawMode_);

public:

	GLenum drawMode;
	GLenum polyMode;

	glm::mat4 view; 
	glm::mat4 projection; 
	std::shared_ptr<Material> material;

	std::shared_ptr<Shader> shader; 
	GLuint VAO, VBO, EBO;
};