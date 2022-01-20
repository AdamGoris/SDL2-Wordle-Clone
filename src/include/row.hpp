#include <SDL.h>
#include <letter.hpp>

class Row
{
  private:
    static const int NUM_LETTERS = 5;
    int x;
    int y;
    int active_letter = 0;

  public:
    Letter letters[5];

    Row(int x_pos, int y_pos)
    {
      x = x_pos;
      y = y_pos;

      // Initialise letter objects

      int* i = new int(0);
      while (*i < NUM_LETTERS)
      {
        // Set the x and y coordinate of the letter

        letters[*i].setPos(x, y);

        // y remains constant, x increases

        x += 150;

        // Increment i

        *i = *i + 1;
      }
      delete i;
    }

    void draw(SDL_Renderer* renderer);
};

void Row::draw(SDL_Renderer* renderer)
{
  // Set the draw color to black

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  // Draw NUM_LETTERS letters

  int* i = new int(0);
  while (*i < NUM_LETTERS)
  {
    letters[*i].draw(renderer);
    *i = *i + 1;
  }
  delete i;
}
