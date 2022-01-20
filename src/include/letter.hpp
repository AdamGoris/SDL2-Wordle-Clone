#include <SDL.h>

class Letter
{
  public:
    int x;
    int y;
    int size;
    char value = '\0'; // the character associated with this letter object
    bool value_is_visible; // whether to show the value in this letter

    Letter(int x_pos, int y_pos, int s)
    {
      value_is_visible = false;
      x = x_pos;
      y = y_pos;
      size = s;
    }

    Letter() // Default constructor
    {
      value_is_visible = false;
      x = 0;
      y = 0;
    }

    void draw(SDL_Renderer* renderer);
    void setPos(int x_pos, int y_pos, int s);
};

void Letter::draw(SDL_Renderer* renderer)
{
  // Draw the outer rect of the letter

  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = size;
  rect.h = size;
  SDL_RenderDrawRect(renderer, &rect);
}

void Letter::setPos(int x_pos, int y_pos, int s)
{
  x = x_pos;
  y = y_pos;
  size = s;
}
