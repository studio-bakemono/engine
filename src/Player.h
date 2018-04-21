#pragma once
#include "SDL.h"
#include "InputManager.h"
#include "vector2.h"

class Player
{
public:

	SDL_Renderer* renderer = nullptr;

	SDL_Texture* tex = nullptr;
	SDL_Surface* surf = nullptr;
	SDL_Rect rect;

	InputManager* input = nullptr;

	Vec2 grid_pos = {2,2};


	void load() {
		if (input == nullptr || renderer == nullptr || tex == nullptr)
			printf("WARNING: Some pointers inside player are still nullptr");
	}

	void update() {

		switch (input->e->type)
		{
		case SDL_KEYDOWN:
			if (input->e->key.keysym.sym == SDLK_RIGHT) {
				printf("NUTTUN 4 SUMTHIN");
			}
			break;

		}

	}

	void render() {

	}

	void cleanup() {
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(tex);
		surf = nullptr;
		tex = nullptr;
		renderer = nullptr;

	}


	Player(SDL_Surface* s, SDL_Renderer* ren, InputManager* inp)
		:surf(s), renderer(ren), input(inp) {}

	~Player();
};

