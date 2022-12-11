#pragma once

#include "../buffer/ImageTexture.h"
#include "../utils/Shader.h"

class Ocean
{
public:
    // texture
    std::shared_ptr<ImageTexture> GaussianRandomRT_Texture;
    std::shared_ptr<ImageTexture> HeightSpectrumRT_Texture;
    std::shared_ptr<ImageTexture> DisplaceXSpectrumRT_Texture;
    std::shared_ptr<ImageTexture> DisplaceZSpectrumRT_Texture;
    std::shared_ptr<ImageTexture> InputRT_Texture;
    std::shared_ptr<ImageTexture> OutputRT_Texture;
    std::shared_ptr<ImageTexture> DisplaceRT_Texture;
    std::shared_ptr<ImageTexture> NormalRT_Texture;
    std::shared_ptr<ImageTexture> BubblesRT_Texture;

    //shaders
    std::shared_ptr<Shader> GaussianRandomRT_Shader;
    std::shared_ptr<Shader> DisplaceSpectrum_Shader;
    std::shared_ptr<Shader> HeightSpectrum_Shader;
    std::shared_ptr<Shader> FFTHorizontal_Shader;
    std::shared_ptr<Shader> FFTHorizontalEnd_Shader;
    std::shared_ptr<Shader> FFTVertical_Shader;
    std::shared_ptr<Shader> FFTVerticalEnd_Shader;
    std::shared_ptr<Shader> TextureDisplace_Shader;
    std::shared_ptr<Shader> TextureNormalBubbles_Shader;

    std::shared_ptr<Shader> draw_shader;

public:
    const int FFTPow = 9;         //���ɺ��������С 2�Ĵ��ݣ��� Ϊ10ʱ�������СΪ1024*1024
    const int fft_size = 512;//fft�����С = pow(2,FFTPow)
    int MeshSize = 100;		//���񳤿�����
    float MeshLength = 512;	//���񳤶�
    float A = 73;			//phillips�ײ�����Ӱ�첨�˸߶�
    float Lambda = 8;       //��������ƫ�ƴ�С
    float HeightScale = 28.8;   //�߶�Ӱ��
    float BubblesScale = 1.0f;  //��ĭǿ��1.0
    float BubblesThreshold = 0.86f;//��ĭ��ֵ 0.86
    float WindScale = 30;     //��ǿ
    float TimeScale = 2;     //ʱ��Ӱ��
    glm::vec4 WindAndSeed = glm::vec4(1.0f, 1.0f, 0, 0);//������������ xyΪ��, zwΪ�����������
    // timing
    float inner_time = 0.0f;//ʱ��
    float deltaTime = 0.0f;	// time between current frame and last frame
    float lastFrame = 0.0f;

public:
    void Start();
    void Update();
    void Draw();

private:
    //Mesh data
    std::vector<unsigned int>vertexIndexs;		//��������������EBO
    //std::vector<glm::vec3> positions;    //λ�� vertex coordinates
    //std::vector<glm::vec2>uvs; 			//uv���� texture coordinates
    std::vector<float> vertexInfo;//positions uvs

    unsigned int VAO, texture_VAO, VBO, EBO;

private:
    //init
    void initTextures();
    void initMesh();
    void initShaders();
    void initGaussianRandom();
    void initClock();

    //compute
    void ComputeFFT(std::shared_ptr<Shader> shader, std::shared_ptr<ImageTexture>input_Texture);
    void ComputeOceanValue();

};
