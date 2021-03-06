#include "renderer.h"
#include "texture.h"
#include "assert.h"
#include <SDL_Image.h>

Texture::Texture()
{
	//
}

Texture::~Texture()
{
	Destroy();
}

bool Texture::Create(const std::string& textureName)
{
	SDL_Surface* surface = IMG_Load(textureName.c_str());
	assert(surface);
	m_sdlTexture = SDL_CreateTextureFromSurface(Renderer::Instance()->GetRenderer(), surface);
	SDL_FreeSurface(surface);

	return true;
}

void Texture::Destroy()
{
	if (m_sdlTexture)
	{
		SDL_DestroyTexture(m_sdlTexture);
		m_sdlTexture = nullptr;
	}
}
