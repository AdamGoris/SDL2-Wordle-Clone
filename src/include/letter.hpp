#include <SDL.h>

class Letter
{
  private:
    const int SIZE = 100;
    int x;
    int y;

  public:
    char value; // the character associated with this letter object
    bool value_is_visible; // whether to show the value in this letter

    Letter(int x_pos, int y_pos)
    {
      value_is_visible = false;
      x = x_pos;
      y = y_pos;
    }

    void draw(SDL_Renderer* renderer);
};

void Letter::draw(SDL_Renderer* renderer)
{
  // Set the draw color to black

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  // Draw the outer rect of the letter

  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = SIZE;
  rect.h = SIZE;
  SDL_RenderDrawRect(renderer, &rect);
}
