#include "audioSystem.h"

#include "assert.h"

bool AudioSystem::Initialize(Engine * engine)
{
	m_engine = engine;

	FMOD_RESULT result = FMOD::System_Create(&m_fmodSystem);
	assert(result == FMOD_OK);
	void* extradriverdata = nullptr; 
	result = m_fmodSystem->init(32, FMOD_INIT_NORMAL, extradriverdata); 
	assert(result == FMOD_OK);

	return true;
}

void AudioSystem::Shutdown()
{
	for (auto& sound : m_sounds)
	{
		sound.second->release();
	}
	m_sounds.clear();

	FMOD_RESULT result = m_fmodSystem->close();
	assert(result == FMOD_OK);

	result = m_fmodSystem->release();
	assert(result == FMOD_OK);
}

void AudioSystem::Update()
{
	FMOD_RESULT result = m_fmodSystem->update();
	assert(result == FMOD_OK);
}

void AudioSystem::AddSound(const std::string & id, const std::string & filename)
{
	assert(m_sounds.find(id) == m_sounds.end());
	FMOD::Sound* fmodSound = nullptr;
	FMOD_RESULT result = m_fmodSystem->createSound(filename.c_str(), FMOD_DEFAULT, 0, &fmodSound);
	if (result == FMOD_OK)
	{
		m_sounds[id] = fmodSound;
	}
	
}

void AudioSystem::PlaySound(const std::string & id)
{
	assert(m_sounds.find(id) != m_sounds.end());
	FMOD::Channel* channel;
	auto iter = m_sounds.find(id);
	if (iter != m_sounds.end())
	{
		//FMOD_MODE mode = (loop) ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
		//iter->second->setMode(mode);
		FMOD_RESULT result = m_fmodSystem->playSound(iter->second, 0, false, &channel);
		assert(result == FMOD_OK);
	}

}

void AudioSystem::RemoveSound(const std::string & id)
{
	assert(m_sounds.find(id) != m_sounds.end());

	auto iter = m_sounds.find(id);
	if (iter != m_sounds.end())
	{
		FMOD::Sound* fmodSound = iter->second;
		FMOD_RESULT result = fmodSound->release();
		assert(result = FMOD_OK);
		m_sounds.erase(iter);
	}
}
