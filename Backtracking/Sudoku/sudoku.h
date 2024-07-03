#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

class Sudoku {
public:
  Sudoku(){};
  Sudoku(int g[][9]) { initializeSudokuGrid(g); }

  void initializeSudokuGrid(int g[][9]) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        grid[i][j] = g[i][j];
      }
    }
  }

  void printSudokuGrid() {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        std::cout << grid[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  bool SolveSudoku() {
    int row, col;
    if (findEmptyGridSlot(row, col)) {
      for (int num = 1; num <= 9; num++) {
        if (canPlaceNum(row, col, num)) {
          grid[row][col] = num;
          if (SolveSudoku()) // recursive call
            return true;
          grid[row][col] = 0;
        }
      }
      return false; // backtrack
    } else
      return true; // there are no empty slots
  }

  bool findEmptyGridSlot(int &row, int &col) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (grid[i][j] == 0) {
          row = i;
          col = j;
          return true;
        }
      }
    }
    return false;
  }

  bool canPlaceNum(int row, int col, int num) {
    if (numAlreadyInRow(row, num) || numAlreadyInCol(col, num) ||
        numAlreadyInBox(row, col, num)) {
      return false;
    }
    return true;
  }

  bool numAlreadyInRow(int row, int num) {
    for (int i = 0; i < 9; i++) {
      if (num == grid[row][i])
        return true;
    }
    return false;
  }

  bool numAlreadyInCol(int col, int num) {
    for (int i = 0; i < 9; i++) {
      if (num == grid[i][col])
        return true;
    }
    return false;
  }

  bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num) {
    int startRow = smallGridRow - smallGridRow % 3;
    int startCol = smallGridCol - smallGridCol % 3;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (num == grid[i + startRow][j + startCol])
          return true;
      }
    }
    return false;
  }

private:
  int grid[9][9];
};

#endif // !SUDOKU_H
