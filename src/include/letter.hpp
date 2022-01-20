#include <SDL.h>

class Letter
{
  private:
    const int SIZE = 50;
    int x;
    int y;

  public:
    char value; // the character associated with this letter object
    bool value_is_visible; // whether to show the value in this letter

    Letter(int x, int y) // Constructor
    {
      value_is_visible = false;
      x = x;
      y = y;
    }
    
    // Letter draw function

    void draw(SDL_Renderer* renderer);
};

void Letter::draw(SDL_Renderer* renderer)
{
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = SIZE;
  rect.h = SIZE;
  SDL_RenderDrawRect(renderer, &rect);
}
