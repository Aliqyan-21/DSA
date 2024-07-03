#ifndef NQUEENSPUZZLE_H
#define NQUEENSPUZZLE_H

#include <iostream>

class NQueensPuzzle {
public:
  NQueensPuzzle(int queens = 8) {
    noOfQueens = queens;
    queensInRow = new int[noOfQueens];
    noOfSolutions = 0;
  }

  bool canPlaceQueen(int row, int col) {
    for (int i = 0; i < row; i++) {
      if ((queensInRow[i] == col) ||
          (abs(queensInRow[i] - col) == (abs(i - row))))
        return false;
    }
    return true;
  }

  // the recursive function to solve the NQueensProblem
  void queensProblemSolver(int k) {
    for (int i = 0; i < noOfQueens; i++) {
      if (canPlaceQueen(k, i)) {
        queensInRow[k] = i;      // place the kth queen in column i
        if (k == noOfQueens - 1) // all queens are placed
          printSolution();
        else
          // determine the place for the (k+1)th queen
          queensProblemSolver(k + 1);
      }
    }
  }

  void printSolution() {
    noOfSolutions++;
    std::cout << "(";
    for (int i = 0; i < noOfQueens - 1; i++)
      std::cout << queensInRow[i] << ", ";
    std::cout << queensInRow[noOfQueens - 1] << ") " << std::endl;
  }

  int solutionsCount() { return noOfSolutions; }

private:
  int noOfSolutions;
  int noOfQueens;
  int *queensInRow;
};

#endif // !NQUEENSPUZZLE_H
