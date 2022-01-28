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

  public:
    vector<Letter> letters;

    Row(int x, int y, int nl, int ls, int lg)
    {
      x_pos = x;
      y_pos = y;
      num_letters = nl;
      letter_size = ls;
      letter_gap = lg;

      /* Set the x and y pos for each letter
      in the letters array */

      for (int i = 0; i < num_letters; i++)
      {
        Letter letter(x_pos, y_pos, letter_size);
        letters.push_back(letter);

        // Increment x_pos of next letter

        x_pos += letter_gap;
      }
    }

    void draw(SDL_Renderer* renderer);
};

void Row::draw(SDL_Renderer* renderer)
{
  // Draw all letters

  for (Letter &letter : letters)
  {
    letter.draw(renderer);
  }
}
