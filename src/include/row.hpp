#include <SDL.h>
#include <letter.hpp>

class Row
{
  private:
    static const int NUM_LETTERS = 5;
    int x_pos;
    int y_pos;
    int letter_size;
    int letter_gap;

  public:
    Letter letters[NUM_LETTERS];

    Row(int x, int y, int ls, int lg)
    {
      x_pos = x;
      y_pos = y;
      letter_size = ls;
      letter_gap = lg;

      /* Set the x and y pos for each letter
      in the letters array */

      for (Letter &letter : letters)
      {
        letter.setPos(x_pos, y_pos, letter_size);

        x_pos += letter_gap;
      }
    }

    Row() = default;

    void draw(SDL_Renderer* renderer);
};

void Row::draw(SDL_Renderer* renderer)
{
  // Set the draw color to black

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  // Draw NUM_LETTERS letters

  for (Letter &letter : letters)
  {
    letter.draw(renderer);
  }
}
