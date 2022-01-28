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

    Row(int x, int y, int n_l, int l_s, int l_g, int a_l)
    {
      x_pos = x;
      y_pos = y;
      num_letters = n_l;
      letter_size = l_s;
      letter_gap = l_g;
      active_letter = a_l;

      /* Set the x and y pos for each letter
      in the letters array. Special case for active letter */

      bool is_active_letter;
      for (int i = 0; i < num_letters; i++)
      {
        is_active_letter = false;
        if (a_l == i)
        {
          is_active_letter = true;
        }
        Letter letter(x_pos, y_pos, letter_size, is_active_letter);
        letters.push_back(letter);

        // Increment x_pos of next letter

        x_pos += letter_gap;
      }
    }

    void draw(SDL_Renderer* renderer);
    void activate(int acl);
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

void Row::activate(int acl)
{
  // Deactivate old active letter

  letters[active_letter].deactivate();

  // Activate new letter

  active_letter = acl;
  letters[active_letter].activate();
}

void Row::deactivate()
{
  // Deactivate letter then deactivate this row

  letters[active_letter].deactivate();
  active_letter = -1;
}
