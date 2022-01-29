#include <SDL.h>
#include <iostream>
#include <grid.hpp>
#include <SDL_ttf.h>

const int W_WIDTH = 1200;
const int W_HEIGHT = 900;

int main(int argv, char** args)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();

  SDL_Window* window = SDL_CreateWindow("Wordle Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  bool isRunning = true;
  SDL_Event event;

  // Initialize Grid of Letters
  // At x,y = 50,50; 5 cols and rows; letter size 100 with gap 50;

  Grid grid(50, 50, 5, 5, 100, 50);

  while (isRunning)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          isRunning = false;
          break;

        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_ESCAPE)
          {
            isRunning = false;
          }
          else if (event.key.keysym.sym == SDLK_RIGHT)
          {
            grid.nextLetter();
          }
          else if (event.key.keysym.sym == SDLK_LEFT)
          {
            grid.previousLetter();
          }
          else if (event.key.keysym.sym >= 97 && event.key.keysym.sym <= 122)
          {
            const char* key = SDL_GetKeyName(event.key.keysym.sym);
            grid.setActiveValue(*key);
          }
      }
    }

    // Clear the renderer

    SDL_RenderClear(renderer);

    // Draw the Grid in black

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    grid.draw(renderer);

    // Draw the background in light grey

    SDL_SetRenderDrawColor(renderer, 230, 230, 230, 255);

    // Render updated renderer

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
