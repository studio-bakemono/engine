#include <iostream>
//#define SDL_MAIN_HANDLED
#include "SDL.h"

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

bool quit = false;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface= nullptr;
SDL_Surface* test = nullptr;

int main() {

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
    SDL_Rect test_rect; 
    test_rect.w = 200;
    test_rect.h = 400;

    while (!quit) {

      SDL_Event e;
      while (SDL_PollEvent(&e) != 0)  {
       if (e.type == SDL_QUIT)
        quit = true;
       
        switch (e.type) {
          case SDL_KEYDOWN:
            switch(e.key.keysym.sym)
            
              case SDLK_LEFT:
                test_rect.x -= 2;
                break;
              
              case SDLK_RIGHT:
                test_rect.x += 2;
                break;

              case SDLK_UP:
                test_rect.y -= 2;
                break;

              case SDLK_DOWN:
                test_rect.y += 2;
                break;
          break;
        }    
      }


      //render

      SDL_BlitSurface(test, NULL, screenSurface, NULL);

      SDL_UpdateWindowSurface(window);
      
    }

SDL_FreeSurface(screenSurface);
SDL_FreeSurface(test);

SDL_DestroyWindow(window);

SDL_Quit();

printf("it works\n");

return 0;
}
