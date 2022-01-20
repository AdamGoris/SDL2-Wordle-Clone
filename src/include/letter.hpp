#include <SDL.h>

class Letter
{
  private:
    const int SIZE = 100;

  public:
    int x;
    int y;
    char value = '\0'; // the character associated with this letter object
    bool value_is_visible; // whether to show the value in this letter

    Letter(int x_pos, int y_pos)
    {
      value_is_visible = false;
      x = x_pos;
      y = y_pos;
    }

    Letter() // Default constructor
    {
      value_is_visible = false;
      x = 0;
      y = 0;
    }

    void draw(SDL_Renderer* renderer);
    void setPos(int x_pos, int y_pos);
};

void Letter::draw(SDL_Renderer* renderer)
{
  // Draw the outer rect of the letter

  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = SIZE;
  rect.h = SIZE;
  SDL_RenderDrawRect(renderer, &rect);
}

void Letter::setPos(int x_pos, int y_pos)
{
  x = x_pos;
  y = y_pos;
}
