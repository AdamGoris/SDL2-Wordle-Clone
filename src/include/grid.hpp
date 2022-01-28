#include <SDL.h>
#include <row.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Grid
{
  private:
    int x_pos;
    int y_pos;
    int num_cols;
    int num_rows;
    int letter_size;
    int letter_gap;

  public:
    vector<Row> rows;

    Grid(int x, int y, int nc, int nr, int ls, int lg)
    {
      x_pos = x;
      y_pos = y;
      num_cols = nc;
      num_rows = nr;
      letter_size = ls;
      letter_gap = ls + lg;

      // Initialise rows vector

      for (int i = 0; i < num_rows; i++)
      {
        Row row(x_pos, y_pos, num_cols, letter_size, letter_gap);
        rows.push_back(row);

        // Increment y pos for next row

        y_pos += letter_gap;
      }
    }
    
    void draw(SDL_Renderer* renderer);
};

void Grid::draw(SDL_Renderer* renderer)
{
  // Draw all rows

  for (Row &row : rows)
  {
    row.draw(renderer);
  }
}
