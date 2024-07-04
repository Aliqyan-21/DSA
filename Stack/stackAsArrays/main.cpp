#include "stackType.h"
#include <fstream>
#include <iomanip>
#include <ios>

int main(void) {
  // initialization of variables
  float GPA;
  float highestGPA;
  std::string name;
  StackType<std::string> stack = StackType<std::string>(100);

  std::ifstream infile("input.txt");
  if (!infile) {
    std::cout << "Input file not found" << std::endl;
    exit(1);
  }

  std::cout << std::fixed << std::showpoint;
  std::cout << std::setprecision(2);

  infile >> GPA >> name;

  highestGPA = GPA;
  while (infile) {
    if (GPA > highestGPA) {
      stack.initializeStack();
      if (!stack.isFullStack())
        stack.push(name);
      highestGPA = GPA;
    } else if (GPA == highestGPA) {
      if (!stack.isFullStack())
        stack.push(name);
      else {
        std::cout << "Stack overflows: Program Terminates" << std::endl;
        exit(1);
      }
    }
    infile >> GPA >> name;
  }

  std::cout << "Highest GPA: " << highestGPA << std::endl;
  std::cout << "Student Holding Highest GPA are: " << std::endl;
  while (!stack.isEmptyStack()) {
    std::cout << stack.top() << std::endl;
    stack.pop();
  }
  std::cout << std::endl;

  return 0;
}
