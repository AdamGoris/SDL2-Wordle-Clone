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

      /* Set the x and y pos for each letter
      in the letters array */

      for (Letter &letter : letters)
      {
        letter.setPos(x,y);

        x += 150;
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
