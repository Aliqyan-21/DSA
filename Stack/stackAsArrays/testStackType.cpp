#include "stackType.h"

void testCopyConstructor(const StackType<int> otherStack) {
  if (!otherStack.isEmptyStack()) {
    std::cout << "Other otherStack is not empty." << std::endl;
    std::cout << "The top element of otherStack: " << otherStack.top()
              << std::endl;
  }
}

int main(void) {
  StackType<int> stack(50);
  StackType<int> anotherStack(50);

  stack.initializeStack();
  stack.push(21);
  stack.push(34);
  stack.push(12);
  anotherStack = stack;

  std::cout << "The elements of anotherStack: ";
  while (!anotherStack.isEmptyStack()) {
    std::cout << anotherStack.top() << " ";
    anotherStack.pop();
  }
  std::cout << std::endl;

  anotherStack = stack;
  testCopyConstructor(stack);

  if (!stack.isEmptyStack()) {
    std::cout << "The original stack is not empty." << std::endl;
    std::cout << "The top element of stack: " << stack.top() << std::endl;
  }

  return 0;
}
