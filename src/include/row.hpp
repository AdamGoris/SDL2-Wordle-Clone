#include <SDL.h>
#include <letter.hpp>

class Row
{
  private:
    static const int NUM_LETTERS = 5;
    int x_pos;
    int y_pos;
    int letter_x_pos;
    int active_letter = 0;
    int letter_size;
    int letter_gap;

  public:
    Letter letters[5];

    Row(int x, int y, int ls)
    {
      x_pos = x;
      y_pos = y;
      letter_x_pos = x;
      letter_size = ls;
      letter_gap = letter_size + 50;

      /* Set the x and y pos for each letter
      in the letters array */

      for (Letter &letter : letters)
      {
        letter.setPos(letter_x_pos, y_pos, letter_size);

        letter_x_pos += letter_gap;
      }
    }

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
