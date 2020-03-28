#pragma once
#include "Common.h"
#include "OpenAssetImportMesh.h"
#include "MatrixStack.h"
#include "Shaders.h"
#include "Camera.h"

//Hello Lady or Gentleman. I am the Imposter horse. 
//This is where I shall tell you more about myself. 
//Look at ImposterHorse.cpp for more details on methods!

class CImposterHorse
{
public:
	CImposterHorse();
	~CImposterHorse();
	
	//Gets 3D attributes of imposter horse
	glm::vec3 GetPosition() const { return m_position; };
	glm::vec3 GetUp() const { return m_up_vector; };
	glm::vec3 GetForward() const { return m_forward_vector; };
	glm::vec3 GetView() const { return m_position + m_forward_vector; }
	void SetPosition(glm::vec3 pos) { m_position = pos; }

	//Methods to integrate imposter horse into the game scene
	void Initialise(COpenAssetImportMesh* object);
	void Render(glutil::MatrixStack playerStack, CShaderProgram* shaderProgram, CCamera* camera);
	void Update(double dt);
	void TranslateByKeyboard(double dt);
	void Advance(double direction);
	void Strafe(double direction);
	void Speed(float& speedfactor);
	void SetMoveHorse(bool shouldMove);
	void SetRotation(float rotation) { m_rotation = rotation; }
	void SetRotationAxis(glm::vec3 axis) { rotation_axis = axis; }
	
private:
	//The mesh to be rendered as the imposter horse
	COpenAssetImportMesh* m_imposter_horse{};

	//3D attributes of imposter horse
	glm::vec3 m_position{ 0.f, 0.0f, 100.f };
	glm::vec3 m_strafe_vector{ 0.f, 0.f, -1.f };
	glm::vec3 m_forward_vector{ -1.f, 0.f, 0.f };
	glm::vec3 m_up_vector{ 0.f, 1.0f, 0.0f };
	float m_rotation = 0.f;
	glm::vec3 rotation_axis{ 0.f, 1.f, 0.f };
	float m_speed = 0.05f;
	bool moveHorse;
};