#pragma once
#include <SDL.h>
#include "EntityManager.h"
#include "Entity.h"

//#include "TextureManager.h"

#include "Player.h"

class App
{
public:

	SDL_Window * window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	//Event handler
	SDL_Event e;
	
	bool running;

	const int WINDOW_WIDTH =  800;
	const int WINDOW_HEIGHT = 600;

	const int FRAMERATE = 60;
	int frametime = 0;

	App();

	bool startup();

	void Load();

	void Update();

	void Render();

	void cleanup();

	void run();

	~App();
};

