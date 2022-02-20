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

    static const int NUM_TOP = 10;
    static const int NUM_MID = 9;
    static const int NUM_BOTTOM = 7;
  
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

      // Initialise arrays for each row in the keyboard

      int top_row[NUM_TOP] = {16, 22, 4, 17, 19, 24, 20, 8, 14, 15}; // Top row is QWERTYUIOP
      int middle_row[NUM_MID] = {0, 18, 3, 5, 6, 7, 9, 10, 11}; // Middle row is ASDFGHJKL
      int bottom_row[NUM_BOTTOM] = {25, 23, 2, 21, 1, 13, 12}; // Bottom row is ZXCVBNM

      // Set x and y position of each letter in each row

      for (int i = 0; i < NUM_TOP; i++) // Top row
      {
        alphabet[top_row[i]].setPos(x, y);
        x += letter_gap;
      }

      x = x_pos + (letter_size / 4); // Reset x with a slight offset
      y += letter_gap;
      for (int i = 0; i < NUM_MID; i++) // Middle row
      {
        alphabet[middle_row[i]].setPos(x, y);
        x += letter_gap;
      }

      x = x_pos + (letter_size / 2); // Reset x with offset
      y += letter_gap;
      for (int i = 0; i < NUM_BOTTOM; i++) // Bottom row
      {
        alphabet[bottom_row[i]].setPos(x, y);
        x += letter_gap;
      }
    }

    void draw(SDL_Renderer* renderer);
};

void Keyboard::draw(SDL_Renderer* renderer)
{
  // Draw each letter in the keyboard

  for (Letter &letter: alphabet)
  {
    letter.draw(renderer);
  }
}
