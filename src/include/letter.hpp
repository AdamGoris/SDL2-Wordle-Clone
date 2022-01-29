#include <SDL.h>
#include <SDL_ttf.h>

class Letter
{
  private:
    int x_pos;
    int y_pos;
    int size;
    char* value = NULL; // the character associated with this letter object
    bool value_is_visible; // whether to show the value in this letter
    bool is_active; // Whether this is the active letter

    // For displaying the letter text

    TTF_Font* sans = TTF_OpenFont("./fonts/OpenSans-Light.ttf", 24);
    SDL_Color black = {0, 0, 0};

  public:
    Letter(int x, int y, int s, bool ia)
    {
      value_is_visible = false;
      x_pos = x;
      y_pos = y;
      size = s;
      is_active = ia;
    }

    void draw(SDL_Renderer* renderer);
    void activate();
    void deactivate();
    void setValue(char* v);
};

void Letter::draw(SDL_Renderer* renderer)
{
  // Draw the border letter

  SDL_Rect rect;
  rect.x = x_pos;
  rect.y = y_pos;
  rect.w = size;
  rect.h = size;
  SDL_RenderDrawRect(renderer, &rect);

  // If this letter has a value, display it

  if (value)
  {

    // Create a rect to display the letter value

    SDL_Rect text_rect;
    text_rect.x = x_pos + 20;
    text_rect.y = y_pos;
    text_rect.w = size - 40;
    text_rect.h = size;

    // Initialise the text surface and texture
    
    SDL_Surface* text_surface = TTF_RenderText_Solid(sans, value, black);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, text_surface);

    // Render the letter on the Rect

    SDL_RenderCopy(renderer, texture, NULL, &text_rect);
    
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(texture);
  }

  // If this letter is active, draw another rect (for now)

  if (is_active)
  {
    SDL_Rect a_rect;
    a_rect.x = x_pos + 5;
    a_rect.y = y_pos + 5;
    a_rect.w = size - 10;
    a_rect.h = size - 10;
    SDL_RenderDrawRect(renderer, &a_rect);
  }
}

void Letter::activate()
{
  is_active = true;
}

void Letter::deactivate()
{
  is_active = false;
}

void Letter::setValue(char* v)
{
  value = v;
}
