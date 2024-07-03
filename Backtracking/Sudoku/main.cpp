#include "sudoku.h"

int main(void) {
  // example grid:
  /*
  int grid[9][9] = {
      {6, 0, 3, 0, 2, 0, 0, 9, 0}, {0, 0, 0, 0, 5, 0, 0, 8, 0},
      {0, 2, 0, 4, 0, 7, 0, 0, 1}, {0, 0, 6, 0, 1, 4, 3, 0, 0},
      {0, 0, 0, 0, 8, 0, 0, 5, 6}, {0, 4, 0, 6, 0, 3, 2, 0, 0},
      {8, 0, 0, 2, 0, 0, 0, 0, 7}, {0, 1, 0, 0, 7, 5, 8, 0, 0},
      {0, 3, 0, 0, 0, 6, 1, 0, 5},
  };
  */

  int grid[9][9];
  std::cout << "Enter Sudoku Grid Here:-" << std::endl;
  for (int i = 0; i < 9; i++) {
    // std::cout << "Enter the value of row " << i + 1
    //           << " seperated with spaces:" << std::endl;
    for (int j = 0; j < 9; j++) {
      std::cin >> grid[i][j];
    }
  }

  Sudoku solver = Sudoku(grid);
  solver.SolveSudoku();
  std::cout << std::endl;
  std::cout << "The Solution of the Provided Sudoku Grid:- " << std::endl;
  solver.printSudokuGrid();

  return 0;
}
