#include <iostream>
#include "SDL.h"

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface= nullptr;
SDL_Surface* test = nullptr;

int main(int argc, char* args[]){


if (SDL_Init( SDL_INIT_VIDEO) < 0) {
  printf("Error! Couldn't init Video! ");
}


  window = SDL_CreateWindow(
    "TEST", 
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH, WINDOW_HEIGHT,
    SDL_WINDOW_SHOWN);

    screenSurface = SDL_GetWindowSurface(window);


    test = SDL_LoadBMP("test.bmp");
    
    SDL_BlitSurface(test, NULL, screenSurface, NULL);


    SDL_UpdateWindowSurface(window);

  SDL_Delay(3000);


SDL_FreeSurface(screenSurface);
SDL_FreeSurface(test);

SDL_DestroyWindow(window);

SDL_Quit();

printf("it works\n");

return 0;
}
