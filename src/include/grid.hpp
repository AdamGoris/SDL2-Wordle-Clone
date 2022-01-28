#include <SDL.h>
#include <row.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Grid
{
  private:
    // x, y for drawing

    int x_pos;
    int y_pos;

    // Number of columns and rows in the grid

    int num_cols;
    int num_rows;

    // Size of each cell and gap between cells

    int letter_size;
    int letter_gap;

    // Active cell tracker

    struct Cell {
      int row;
      int col;
    } active_cell;

  public:
    vector<Row> rows;

    Grid(int x, int y, int nc, int nr, int ls, int lg)
    {
      // Initialise given values

      x_pos = x;
      y_pos = y;
      num_cols = nc;
      num_rows = nr;
      letter_size = ls;
      letter_gap = ls + lg;

      // Initial active cell is 0, 0

      active_cell.row = 0;
      active_cell.col = 0;

      // Initialise rows vector. Special case for active row

      for (int i = 0; i < num_rows; i++)
      {
        int* al = new int(-1);
        if (i == active_cell.row)
        {
          *al = i;
        } 
        Row row(x_pos, y_pos, num_cols, letter_size, letter_gap, *al);
        rows.push_back(row);
        delete al;

        // Increment y pos for next row

        y_pos += letter_gap;
      }
    }
    
    void draw(SDL_Renderer* renderer);
    void nextActiveLetter();
};

void Grid::draw(SDL_Renderer* renderer)
{
  // Draw all rows

  for (Row &row : rows)
  {
    row.draw(renderer);
  }
}

void Grid::nextActiveLetter() {
  /* If col is equal to num cols
  AND row is equal to num rows, can't increment any more */

  if (active_cell.col >= num_cols - 1 && active_cell.row >= num_rows - 1)
  {
    return;
  }

  /* If col is equal to number of cols, 
  AND row is less than num rows, 
  reset col and increment row. */ 

  if (active_cell.col >= num_cols - 1)
  {
    active_cell.col = 0;
    active_cell.row++;

    // Also 

    return;
  }

  // Otherwise, simply increment col

  active_cell.col ++;
}
