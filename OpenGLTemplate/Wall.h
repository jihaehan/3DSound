#pragma once
#include "Plane.h"
#include "include/fmod_studio/fmod_common.h"

#include "Texture.h"
#include "VertexBufferObject.h"

class Wall {
private:
	CPlane* plane;

	UINT m_vao;
	CVertexBufferObject m_vbo;
	CTexture m_texture;
	string m_directory;
	string m_filename;

	glm::vec3 vertices[4];
public:
	void create(glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 v4, string directory, string path, float textureRepeat);
	void render();
	void release();
	glm::vec3 getVertex(int index);
};