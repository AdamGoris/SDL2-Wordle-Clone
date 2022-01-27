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
    int num_rows;

  public:
    vector<Row> rows;

    Grid(int x, int y, int nr)
    {
      x_pos = x;
      y_pos = y;
      num_rows = nr;

      // Initialise rows vector

      for (int i = 0; i < num_rows; i++)
      {
        Row row(x_pos, y_pos, 100);
        rows.push_back(row);

        // Increment y pos for next row

        y_pos += 150;
      }
    }
    
    void draw(SDL_Renderer* renderer);
};

void Grid::draw(SDL_Renderer* renderer)
{
  // Set the draw color to black

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  for (Row &row : rows)
  {
    row.draw(renderer);
  }
}
