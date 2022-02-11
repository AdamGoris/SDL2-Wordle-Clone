#include <SDL.h>

class Keyboard
{
  private:
    int x_pos; // Initial x_pos, y_pos is the top left point of the 'Q' Letter
    int y_pos;
    int letter_size; // The size of each Letter
  
  public:
  Keyboard(int x, int y, int l_s)
  {
    x_pos = x;
    y_pos = y;
    letter_size = l_s;
  }
};
