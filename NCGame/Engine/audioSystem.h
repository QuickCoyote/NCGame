#pragma once

#include "engine.h"
#include "singleton.h"
#include "fmod.hpp"
#include <map>
#include <iostream>

class ENGINE_API AudioSystem : public Singleton<AudioSystem>
{
public:
	bool Initialize(Engine* engine);
	void Shutdown();

	void Update();

	void AddSound(const std::string& id, const std::string& filename); 
	void PlaySound(const std::string& id); 
	void RemoveSound(const std::string& id);

	friend Singleton<AudioSystem>;

protected:
	AudioSystem() {}

private:
	Engine * m_engine;
	FMOD::System* m_fmodSystem;
	std::map<std::string, FMOD::Sound*> m_sounds;

};
