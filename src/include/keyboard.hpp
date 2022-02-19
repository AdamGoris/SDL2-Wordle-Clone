#pragma once
#include <SDL.h>
#include <letter.hpp>
#include <vector>

using namespace std;

class Keyboard
{
  private:
    int x_pos; // Initial x_pos, y_pos is the top left point of the 'Q' Letter
    int y_pos;
    int letter_size; // The size of each Letter
    int letter_gap;
  
  public:
    vector<Letter> alphabet;

    Keyboard(int x, int y, int l_s, int l_g)
    {
      x_pos = x;
      y_pos = y;
      letter_size = l_s;
      letter_gap = l_s + l_g;

      // Initialise vector of Letters for each letter in the alphabet

      int ascii = 65;
      for (int i = 0; i < 26; i++)
      {
        Letter letter(char(ascii), l_s);
        alphabet.push_back(letter);

        ascii++;
      }
    }

    void draw(SDL_Renderer* renderer);
};


