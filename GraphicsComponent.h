#pragma once
#include "Component.h"
#include "SDL.h"

class GraphicsComponent : public Component
{
public:

	SDL_Surface tex;
	SDL_Rect size;

	void cleanup();

	void update(SDL_Renderer* renderer) 
	{
		
	}

	GraphicsComponent();
	~GraphicsComponent();
};

