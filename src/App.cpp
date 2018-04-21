#include "stdafx.h"
#include "App.h"


App::App()
{
}

//					AYO, HOL UP! THIS THE STARTUP SHIEEEEET??!?
bool App::startup()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
	//	LogError();
		return false;
	}

	running = true;

	window = SDL_CreateWindow("Test", 200, 200,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED);

	screenSurface = SDL_GetWindowSurface(window);
	if (!screenSurface)
	{
		//LogError(); 
		return false;
	}
	return true;

}



// THIS IS THE LOAD FUNCTION IT LOADS SHIT  *BLOWS MIND*
void App::Load()
{

	texture_manager = new TextureManager(*renderer);

	test_surf = SDL_LoadBMP("test.bmp");

	test_map = map();

	test_tex = nullptr;
	test_tex = SDL_CreateTextureFromSurface( renderer, test_surf );

	//texture_manager->textures[0] = test_tex;


	test_rect = new SDL_Rect{32,32,32,32};


	test_map.load(renderer);


}

void App::Update()
{


	//SDL_GetMouseState(&mouse_position.x, &mouse_position.y);
	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{
		case SDL_MOUSEMOTION:
			printf("THERE IS MOUSE MOTION\n mouse position: (%d, %d)\n",
				e.motion.x, e.motion.y);
				break;

		case SDL_KEYDOWN:
			printf("KEYBOARD INPUT FROM KEY: %d \n", e.key.keysym.sym);

			break;


		case SDL_MOUSEBUTTONDOWN:
			printf("MOUSE INPUT FROM KEY: %d \n", e.button.button);
			break;

		case SDL_MOUSEBUTTONUP:
			break;

		case SDL_QUIT:

			running = false;

			break;
		}

		SDL_Delay(1 / FRAMERATE);


	}





	Render();
	//SDL_UpdateWindowSurface(window);

}





//				WE WUZ RENDERAN N SHIEEEEET
void App::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, test_tex, NULL, test_rect);
	//SDL_BlitSurface(test_surf, NULL, screenSurface, NULL);
	
	test_map.render(renderer);
	
	SDL_RenderPresent(renderer);
	SDL_Delay(1/60);
}

void App::run()
{
	//Do startup operations
	startup();
	Load();
	while (running)
	{
		Update();
	}
	//cleanup();
}

void App::cleanup()
{
	//delete texture_manager;

	entity_manager.cleanup();


	test_map.cleanup();


	SDL_DestroyTexture(test_tex);
	test_tex = nullptr;

	//SDL_Delay(3000);


	SDL_FreeSurface(screenSurface);
	screenSurface = nullptr;

	SDL_DestroyWindow(window);
	window = nullptr;



	SDL_DestroyRenderer(renderer);
	renderer = nullptr;

	SDL_Quit();
}

App::~App()
{
	cleanup();
}
