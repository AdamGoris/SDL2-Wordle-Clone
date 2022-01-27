#include <SDL.h>

class Letter
{
  private:
    int x_pos;
    int y_pos;
    int size;
    char value = '\0'; // the character associated with this letter object
    bool value_is_visible; // whether to show the value in this letter

  public:
    Letter(int x, int y, int s)
    {
      value_is_visible = false;
      x_pos = x;
      y_pos = y;
      size = s;
    }

    void draw(SDL_Renderer* renderer);
    void setPos(int x_pos, int y_pos, int s);
};

void Letter::draw(SDL_Renderer* renderer)
{
  // Draw the outer rect of the letter

  SDL_Rect rect;
  rect.x = x_pos;
  rect.y = y_pos;
  rect.w = size;
  rect.h = size;
  SDL_RenderDrawRect(renderer, &rect);
}

void Letter::setPos(int x, int y, int s)
{
  x_pos = x;
  y_pos = y;
  size = s;
}
