#pragma once

#include "object.h"

class ENGINE_API Texture : public Object
{
public:
	Texture();
	~Texture();

	bool Create(const std::string& textureName);
	void Destroy();

	friend class Renderer;

protected:
	SDL_Texture* m_sdlTexture;
};