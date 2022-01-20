#include <SDL.h>
#include <iostream>
#include <row.hpp>

const int W_WIDTH = 1200;
const int W_HEIGHT = 900;

int main(int argv, char** args)
{
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window* window = SDL_CreateWindow("Wordle Clone", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W_WIDTH, W_HEIGHT, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  bool isRunning = true;
  SDL_Event event;

  // Initialize Row of Letters

  Row row(50, 50, 100);

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
      }
    }

    // Clear the renderer

    SDL_RenderClear(renderer);

    // Draw the Row

    row.draw(renderer);

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
