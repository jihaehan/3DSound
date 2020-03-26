#include "ImposterHorse.h"

CImposterHorse::CImposterHorse() {}
CImposterHorse::~CImposterHorse() {}

void CImposterHorse::Initialise(COpenAssetImportMesh* object)
{
	m_imposter_horse = object;
}

void CImposterHorse::Render(glutil::MatrixStack matrixStack, CShaderProgram* shaderProgram, CCamera* camera)
{
	matrixStack.Push();
	matrixStack.Translate(m_position);
	matrixStack.Scale({ 4.f });
	shaderProgram->SetUniform("matrices.modelViewMatrix", matrixStack.Top());
	shaderProgram->SetUniform("matrices.normalMatrix", camera->ComputeNormalMatrix(matrixStack.Top()));
	m_imposter_horse->Render();
	matrixStack.Pop();
}

void CImposterHorse::Update(double dt)
{
	TranslateByKeyboard(dt);
}

void CImposterHorse::Speed(float& speedfactor)
{
	m_speed = 0.05f * speedfactor;
}

void CImposterHorse::SetMoveHorse(bool shouldMove)
{
	moveHorse = shouldMove;
}

void CImposterHorse::Advance(double direction)
{
	float speed = (float)(m_speed * direction);

	glm::vec3 view = glm::normalize(m_forward_vector);
	m_position = m_position + view * speed;
}

void CImposterHorse::Strafe(double direction)
{
	float speed = (float)(m_speed * direction);

	glm::vec3 view = glm::normalize(m_strafe_vector);
	m_position = m_position + view * speed;
}

void CImposterHorse::TranslateByKeyboard(double dt)
{
	//if horse can't move, don't execute this function
	if (!moveHorse) return;

	if (GetKeyState(VK_UP) & 0x80 || GetKeyState('W') & 0x80) {
		Advance(1.0 * dt);
	}
	if (GetKeyState(VK_DOWN) & 0x80 || GetKeyState('S') & 0x80) {
		Advance(-1.0 * dt);
	}
	if (GetKeyState(VK_LEFT) & 0x80 || GetKeyState('A') & 0x80) {
		Strafe(-1.0 * dt);
	}
	if (GetKeyState(VK_RIGHT) & 0x80 || GetKeyState('D') & 0x80) {
		Strafe(1.0 * dt);
	}
}

