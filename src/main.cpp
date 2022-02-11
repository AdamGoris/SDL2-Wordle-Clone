#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <grid.hpp>
#include <words.hpp>

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

  // Get the word the player has to guess

  string* word_to_guess = new string;
  word_to_guess = getWordToGuess(word_to_guess);
  for (auto &c: *word_to_guess) c = toupper(c); // convert word_to_guess to uppercase

  // Initialize Grid of Letters
  // At x,y = 50,50; 6 rows, 5 cols; letter size 85 with gap 35;

  Grid grid(50, 50, 6, 5, 85, 35, word_to_guess);

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
            // Set active letter to the pressed value and move to the next letter

            const char* key = SDL_GetKeyName(event.key.keysym.sym);
            grid.setActiveLetterValue(*key);
            grid.nextLetter();
          }
          else if (event.key.keysym.sym == SDLK_BACKSPACE)
          {
            // Clear letter value and move to previous letter

            grid.clearActiveLetter();
            grid.previousLetter();
          }
          else if (event.key.keysym.sym == SDLK_RETURN)
          {
            grid.checkActiveRow();
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
  TTF_Quit();

  return 0;
}
