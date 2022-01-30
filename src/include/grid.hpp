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

    Grid(int x, int y, int n_c, int n_r, int l_s, int l_g)
    {
      // Initialise given values

      x_pos = x;
      y_pos = y;
      num_cols = n_c;
      num_rows = n_r;
      letter_size = l_s;
      letter_gap = letter_size + l_g;

      // Initial active cell is 0, 0

      active_cell.row = 0;
      active_cell.col = 0;

      // Initialise rows vector. Special case for active row
      int a_l;
      for (int i = 0; i < num_rows; i++)
      {
        a_l = -1; // -1 for inactive letter
        if (i == active_cell.row)
        {
          a_l = i;
        } 
        Row row(x_pos, y_pos, num_cols, letter_size, letter_gap, a_l);
        rows.push_back(row);

        // Increment y pos for next row

        y_pos += letter_gap;
      }
    }
    
    void draw(SDL_Renderer* renderer);
    void nextLetter();
    void previousLetter();
    void nextRow();
    void previousRow();
    void setActiveValue(char v);
    void clearActiveLetter();
};

// Draw the Grid

void Grid::draw(SDL_Renderer* renderer)
{
  // Draw all rows

  for (Row &row : rows)
  {
    row.draw(renderer);
  }
}

// Move active to the next letter

void Grid::nextLetter()
{
  // If column limit is reached, ignore

  if (active_cell.col >= num_cols - 1)
  {
    return;
  }

  // Otherwise, Increment col and activate next col

  active_cell.col++;
  rows[active_cell.row].nextLetter();
}

// Move active to the previous letter

void Grid::previousLetter()
{
  // If column is already 0, ignore

  if (active_cell.col <= 0)
  {
    return;
  }

  // Otherwise, Decrement col and activate previous col

  active_cell.col--;
  rows[active_cell.row].previousLetter();
}

// Go to the next row

void Grid::nextRow()
{
  active_cell.row++;
}

// Go to the previous active row

void Grid::previousRow()
{
  active_cell.row--;
}

// Set the value of the active letter to v

void Grid::setActiveValue(char v)
{
  rows[active_cell.row].setActiveValue(v);

  // Move to the next cell

  nextLetter();
}

// Clear the value of the active letter

void Grid::clearActiveLetter()
{
  rows[active_cell.row].clearActiveLetter();
}
