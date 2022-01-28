#include <SDL.h>
#include <letter.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Row
{
  private:
    int x_pos;
    int y_pos;
    int num_letters;
    int letter_size;
    int letter_gap;
    int active_letter; // set to 0 to num_letters-1, or -1 if this is not the active row

  public:
    vector<Letter> letters;

    Row(int x, int y, int nl, int ls, int lg, int al)
    {
      x_pos = x;
      y_pos = y;
      num_letters = nl;
      letter_size = ls;
      letter_gap = lg;
      active_letter = al;

      /* Set the x and y pos for each letter
      in the letters array. Special case for active letter */

      for (int i = 0; i < num_letters; i++)
      {
        bool* is_active_letter = new bool(false);
        if (al == i)
        {
          *is_active_letter = true;
        }
        Letter letter(x_pos, y_pos, letter_size, *is_active_letter);
        letters.push_back(letter);
        delete is_active_letter;

        // Increment x_pos of next letter

        x_pos += letter_gap;
      }
    }

    void draw(SDL_Renderer* renderer);
    void activate(int al);
    void deactivate();
};

void Row::draw(SDL_Renderer* renderer)
{
  // Draw all letters

  for (Letter &letter : letters)
  {
    letter.draw(renderer);
  }
}

void Row::activate(int al)
{
  // Deactivate old active letter

  letters[active_letter].deactivate();

  // Activate new letter

  active_letter = al;
  letters[active_letter].activate();
}

void Row::deactivate()
{
  // Deactivate letter then deactivate this row

  letters[active_letter].deactivate();
  active_letter = -1;
}
