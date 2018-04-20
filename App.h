#pragma once
#include "SDL.h"
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


	//TextureManager* texture_manager;
	EntityManager entity_manager;


	SDL_Texture* test_tex;
	SDL_Surface* test_surf;

	SDL_Rect* test_rect;



	struct map {

		int tex_width = 32;
		int tex_height = 32;
		SDL_Surface* test_surf = nullptr;
		SDL_Texture* tex = nullptr;

		vector<vector<bool>>collision_map = {
			{ 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1 }
		};
		vector<vector<int>>texture_map = {
			{ 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1 }
		};


		void load(SDL_Renderer* ren) {
			test_surf = SDL_LoadBMP("map.bmp");
			tex = SDL_CreateTextureFromSurface(ren, test_surf);
		}

		void render( SDL_Renderer* ren ) {
			for (int x = 0; x < texture_map.size(); x++ ) {
				for (int y = 0; y < texture_map[x].size(); y++) {
					if (texture_map[y][x] == 1) {
						SDL_RenderCopy(ren, tex, NULL , new SDL_Rect{x*tex_width, y*tex_height, tex_width, tex_height });
					}
				}
			}
		}

		void cleanup() {
			SDL_FreeSurface(test_surf);
			SDL_DestroyTexture(tex);
		}

	};

	map test_map;



	App();

	bool startup();

	void Load();

	void Update();

	void Render();

	void cleanup();

	void run();

	~App();
};

