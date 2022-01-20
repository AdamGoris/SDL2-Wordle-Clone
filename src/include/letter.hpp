#include <SDL.h>

class Letter
{
  public:
    char value; // the character associated with this letter object
    bool value_is_visible; // whether to show the value in this letter

    // Letter object constructor

    Letter()
    {
      value_is_visible = false;
    }
};
