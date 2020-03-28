#pragma once
#include <windows.h>									// Header File For The Windows Library
#include "./include/fmod_studio/fmod.hpp"
#include "./include/fmod_studio/fmod_errors.h"
#include "Common.h"
#include "Camera.h"
#include "ImposterHorse.h"
#include "Wall.h"

class CAudio
{
public:
	CAudio();
	~CAudio();
	bool Initialise();
	bool LoadEventSound(char *filename);
	bool PlayEventSound();
	bool LoadMusicStream(char *filename);
	bool PlayMusicStream();
	bool Load3DSound(char* filename);
	void Play3DSound();
	void FilterSwitch();	
	void SpeedUp(float &speedpercent);
	void SpeedDown(float &speedpercent);
	void Update(float dt);
	void UpdateListener(glm::vec3 position, glm::vec3 velocity, glm::vec3 forward, glm::vec3 up);
	void Update3DSound(glm::vec3 posiiton, glm::vec3 velocity);

	void CreateObstacle(Wall* wall);

	void ObstacleActivate(bool shouldActivate);
private:
	FMOD_VECTOR listenerVelocity, listenerUp, listenerForward, listenerPos, soundPosition, soundVelocity;
	FMOD::Geometry* geometry;
	FMOD_RESULT result;
	FMOD::System *m_FmodSystem;	// the global variable for talking to FMOD
	FMOD::Sound *m_eventSound;

	FMOD::Sound *m_music;
	FMOD::Channel *m_musicChannel;
	FMOD::ChannelGroup* m_mastergroup;
	FMOD::DSP *m_dsp;

	bool bypass;
	void ToFMODVector(glm::vec3 vec, FMOD_VECTOR* fVec);

};
typedef struct
{
	float* circ_buffer;
	float volume_linear;
	float speed_percent;
	int   sample_count;
	int   channels;

	float* b_filter1;
	float* b_filter2;

} mydsp_data_t;