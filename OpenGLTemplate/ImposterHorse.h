#pragma once
#include "Common.h"
#include "OpenAssetImportMesh.h"
#include "MatrixStack.h"
#include "Shaders.h"
#include "Camera.h"

class CImposterHorse
{
public:
	CImposterHorse();
	~CImposterHorse();
	
	glm::vec3 GetPosition() const { return m_position; };
	glm::vec3 GetUp() const { return m_up_vector; };
	glm::vec3 GetForward() const { return m_forward_vector; };
	glm::vec3 GetView() const { return m_position + m_forward_vector; }

	void Initialise(COpenAssetImportMesh* object);
	void Render(glutil::MatrixStack playerStack, CShaderProgram* shaderProgram, CCamera* camera);
	void Update(double dt);
	void TranslateByKeyboard(double dt);
	void Advance(double direction);
	void Strafe(double direction);
	void Speed(float& speedfactor);
	void SetMoveHorse(bool shouldMove);
private:
	COpenAssetImportMesh* m_imposter_horse{};
	glm::vec3 m_position{ 0.f, 0.0f, 100.f };
	glm::vec3 m_strafe_vector{ 0.f, 0.f, -1.f };
	glm::vec3 m_forward_vector{ -1.f, 0.f, 0.f };
	glm::vec3 m_up_vector{ 0.f, 1.0f, 0.0f };
	float m_speed = 0.05f;
	bool moveHorse;
};