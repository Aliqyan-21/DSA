#include "nQueensPuzzle.h"

int main(void) {
  int n;

  std::cout << "Enter the No. of Queens: ";
  std::cin >> n;
  NQueensPuzzle queenPuzzle = NQueensPuzzle(n);

  queenPuzzle.queensProblemSolver(0);
  std::cout << std::endl;

  std::cout << "The Total No. of solutions that are generated are: "
            << queenPuzzle.solutionsCount() << " Distinct Solutions."
            << std::endl;

  return 0;
}
