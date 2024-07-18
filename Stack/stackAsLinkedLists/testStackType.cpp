#include "stackType.h"

int main(void) {
  StackType<int> stack;
  StackType<int> otherStack;

  stack.push(21);
  stack.push(22);
  stack.push(23);
  otherStack = stack;
  std::cout << "otherStack:" << std::endl;
  while (!otherStack.isEmptyStack()) {
    std::cout << otherStack.top() << std::endl;
    otherStack.pop();
  }
  return 0;
}
