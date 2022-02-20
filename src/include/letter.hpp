#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

class Letter
{
  private:
    int x_pos;
    int y_pos;
    int size;
    bool value_is_visible; // whether to show the value in this letter
    bool is_active; // Whether this is the active letter
    char value = '\0'; // the character associated with this letter object
    struct {
      int r = 245;
      int g = 245;
      int b = 245;
      int a = 255;
    } background;

    // For displaying the letter text

    TTF_Font* sans = TTF_OpenFont("./fonts/OpenSans-Light.ttf", 24);
    SDL_Color black = {0, 0, 0};

  public:
    Letter(int x, int y, int s, bool i_a)
    {
      value_is_visible = false;
      x_pos = x;
      y_pos = y;
      size = s;
      is_active = i_a;
    }

    Letter(char v, int s)
    {
      value = v;
      value_is_visible = true;
      x_pos = 0;
      y_pos = 0;
      size = s;
      is_active = false;
    }

    void draw(SDL_Renderer* renderer);
    void setPos(int x, int y);
    void activate();
    void deactivate();
    char getValue();
    void setValue(char v);
    void clearValue();
    bool hasValue();
    void inWord();
    void notInWord();
    void inPosition();
};

void Letter::draw(SDL_Renderer* renderer)
{
  // Draw the border rectangle

  // Set drawing color to this letter's color

  SDL_SetRenderDrawColor(renderer, background.r, background.g, background.b, background.a);

  SDL_Rect rect;
  rect.x = x_pos;
  rect.y = y_pos;
  rect.w = size;
  rect.h = size;
  SDL_RenderFillRect(renderer, &rect);

  // Set render color back to black

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  // If this letter has a value, display it

  if (value != '\0')
  {

    // Create a rect to display the letter value

    SDL_Rect text_rect;
    text_rect.x = x_pos + (size / 4);
    text_rect.y = y_pos;
    text_rect.w = size / 2;
    text_rect.h = size;

    // Initialise the text surface and textureq
    
    SDL_Surface* text_surface = TTF_RenderText_Solid(sans, &value, black);
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

void Letter::setPos(int x, int y)
{
  x_pos = x;
  y_pos = y;
}

void Letter::activate()
{
  is_active = true;
}

void Letter::deactivate()
{
  is_active = false;
}

char Letter::getValue()
{
  return value;
}

void Letter::setValue(char v)
{
  value = v;
}

void Letter::clearValue()
{
  value = '\0';
}

bool Letter::hasValue()
{
  return value != '\0';
}

// This letter is in the word to guess, color it yellow

void Letter::inWord()
{
  background.r = 214;
  background.g = 195;
  background.b = 24;
}

// This letter is not in the word to guess, color it grey

void Letter::notInWord()
{
  background.r = 190;
  background.g = 190;
  background.b = 190;
}

// This letter is in the word to guess in its correct position, color it green

void Letter::inPosition()
{
  background.r = 58;
  background.g = 163;
  background.b = 49;
}
