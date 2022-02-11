#include <SDL.h>
#include <letter.hpp>
#include <vector>
#include <string>

using namespace std;

class Grid
{
  private:

    // x, y positions for drawing

    int x_pos;
    int y_pos;

    // Number of rows and columns in the grid

    int num_rows;
    int num_cols;

    // Size of each letter cell and distance between cells

    int letter_size;
    int letter_gap;

    // Active cell tracker

    struct Cell {
      int row;
      int col;
    } active_cell;

    // The word that the player is trying to guess

    string* word_to_guess;

    public:
      vector<vector<Letter>> grid;

      Grid(int x, int y, int n_r, int n_c, int l_s, int l_g, string* w_t_g)
      {
        // Initialise given values

        x_pos = x;
        y_pos = y;
        num_rows = n_r;
        num_cols = n_c;
        letter_size = l_s;
        letter_gap = l_s + l_g;
        word_to_guess = w_t_g;

        // Initialise active cell at 0,0

        active_cell.row = 0;
        active_cell.col = 0;

        // Initialise all cells in the grid
        // For each row, initialise num_cols Letters

        for (int r = 0; r < num_rows; r++)
        {
          // Initialise the row

          vector<Letter> row;
          for (int c = 0; c < num_cols; c++)
          {
            // Add Letter for each column

            Letter letter(x_pos, y_pos, letter_size, false);
            row.push_back(letter);

            // Move x_pos

            x_pos += letter_gap;
          }

          // Add the row to the grid

          grid.push_back(row);

          // Increment y_pos, reset x_pos

          y_pos += letter_gap;
          x_pos = x;
        }

        // Set the initial active Letter 0,0

        grid[0][0].activate();
      }

      void draw(SDL_Renderer* renderer);
      void nextLetter();
      void previousLetter();
      void nextRow();
      void previousRow();
      void setActiveLetterValue(char v);
      void clearActiveLetter();
      string extractRowWord();
      void checkActiveRow();
};

// Draw the Grid of Letters

void Grid::draw(SDL_Renderer* renderer)
{
  // Draw each Letter in the letters grid

  for (vector<Letter> &rows : grid)
  {
    for (Letter &letter : rows)
    {
      letter.draw(renderer);
    }
  }
}

// Move to the next letter in the row

void Grid::nextLetter()
{
  // If column limit is reached, ignore

  if (active_cell.col >= num_cols - 1)
  {
    return;
  }

  // Otherwise, deactivate active letter and activate the next

  grid[active_cell.row][active_cell.col].deactivate();
  active_cell.col++;
  grid[active_cell.row][active_cell.col].activate();
}

// Move to the previous letter in the row

void Grid::previousLetter()
{
  // If column is already 0, ignore

  if (active_cell.col <= 0)
  {
    return;
  }

  // Otherwise, deactivate current letter and activate the previous

  grid[active_cell.row][active_cell.col].deactivate();
  active_cell.col--;
  grid[active_cell.row][active_cell.col].activate();
}

// Move to the next Row in the Grid

void Grid::nextRow()
{
  // If row limit is reached, ignore

  if (active_cell.row >= num_rows - 1)
  {
    return;
  }

  // Otherwise, deactivate current letter, move to next row, reset column

  grid[active_cell.row][active_cell.col].deactivate();
  active_cell.row++;
  active_cell.col = 0;
  grid[active_cell.row][active_cell.col].activate();
}

// Move to the previous Row in the Grid
// NOTE: In the game this should not be possible

void Grid::previousRow()
{
  // If row is already 0, ignore

  if (active_cell.row <= 0)
  {
    return;
  }

  // Otherwise, deactivate current letter, move to previous row, set column to max

  grid[active_cell.row][active_cell.col].deactivate();
  active_cell.row--;
  active_cell.col = num_cols - 1;
  grid[active_cell.row][active_cell.col].activate();
}

// Set the value of the active letter to char v

void Grid::setActiveLetterValue(char v)
{
  grid[active_cell.row][active_cell.col].setValue(v);
}

// Clear the value of the active letter

void Grid::clearActiveLetter()
{
  // If active letter is already clear, clear the letter before this one instead

  if (!grid[active_cell.row][active_cell.col].hasValue())
  {
    previousLetter();
  }

  grid[active_cell.row][active_cell.col].clearValue();
}

// Extract the word from the active row

string Grid::extractRowWord()
{
  // Construct a string of all characters in the row

  string row_word;
  for (Letter &letter : grid[active_cell.row])
  {
    // If any letter has not been set, ignore

    if (!letter.hasValue())
    {
      return "";
    }

    // Otherwise, add the letters value to the string

    row_word += letter.getValue();
  }

  return row_word;
}

// Check the word in the active row against the word to guess

void Grid::checkActiveRow()
{
  // construct the word from the active row

  string row_word = extractRowWord();

  // If word not valid, ignore check

  if (row_word == "")
  {
    return;
  }

  // Check matches in entered word against word to guess

  Letter* letter;
  bool in_word;
  for (int i = 0; i < row_word.length(); i++)
  {
    // Get the letter object corresponding to this value

    letter = &grid[active_cell.row][i];
    in_word = false;
    for (int j = 0; j < (*word_to_guess).length(); j++)
    {
      if (row_word.at(i) == (*word_to_guess).at(j))
      {
        in_word = true;

        // Check if in same position

        if (i == j)
        {
          letter->inPosition();
          break;
        }

        letter->inWord();
        break;
      }
    }

    // Check if the letter was not in the word

    if (!in_word)
    {
      letter->notInWord();
    }
  }

  // Also move on to the next row

  nextRow();
}
