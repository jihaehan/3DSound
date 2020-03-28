#include "ImposterHorse.h"

CImposterHorse::CImposterHorse() {}
CImposterHorse::~CImposterHorse() {}

//Initializes a mesh as the imposter horse. 
//It's always an honour to be the imposter horse. 
void CImposterHorse::Initialise(COpenAssetImportMesh* object)
{
	m_imposter_horse = object;
}

//Renders the imposter horse into the scene. 
//Now you get to see glassy-eyed horsey goodness. 
void CImposterHorse::Render(glutil::MatrixStack matrixStack, CShaderProgram* shaderProgram, CCamera* camera)
{
	matrixStack.Push();
	matrixStack.Translate(m_position);
	matrixStack.Rotate(rotation_axis, m_rotation);
	matrixStack.Scale({ 4.f });
	shaderProgram->SetUniform("matrices.modelViewMatrix", matrixStack.Top());
	shaderProgram->SetUniform("matrices.normalMatrix", camera->ComputeNormalMatrix(matrixStack.Top()));
	m_imposter_horse->Render();
	matrixStack.Pop();
}

//Allows the imposter horse to be controlled by keyboard inputs.
void CImposterHorse::Update(double dt)
{
	TranslateByKeyboard(dt);
}

//Sets the speed of imposter horse. 
void CImposterHorse::Speed(float& speedfactor)
{
	m_speed = 0.05f * speedfactor;
}

//Toggles the ability to move the horse using key inputs (as opposed to the player/camera)
void CImposterHorse::SetMoveHorse(bool shouldMove)
{
	moveHorse = shouldMove;
}

//Helper function to move the imposter horse forward and backward upon key presses
void CImposterHorse::Advance(double direction)
{
	float speed = (float)(m_speed * direction);

	glm::vec3 view = glm::normalize(m_forward_vector);
	m_position = m_position + view * speed;
}

//Helper function to move the imposter horse left and right upon key presses
void CImposterHorse::Strafe(double direction)
{
	float speed = (float)(m_speed * direction);

	glm::vec3 view = glm::normalize(m_strafe_vector);
	m_position = m_position + view * speed;
}

//Registers keyboard inputs with the imposter horse movements
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

