#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "../stack.h"
#include <iostream>

template <typename T> class StackType : public Stack<T> {
public:
  const StackType<T> &operator=(const StackType<T> &otherStack) {
    if (this != &otherStack) // avoid self copy
      copyStack(otherStack);
    return *this;
  }

  void initializeStack() override { stackTop = 0; }

  bool isEmptyStack() const override { return stackTop == 0; }

  bool isFullStack() const override { return stackTop == maxStackSize; }

  void push(const T &newItem) override {
    if (!isFullStack()) {
      list[stackTop] = newItem;
      stackTop++;
    } else
      std::cout << "Cannot add to a full stack" << std::endl;
  }

  T top() const override {
    if (!isEmptyStack()) {
      return list[stackTop - 1];
    } else
      std::cout << "Stack is empty" << std::endl;
    exit(1);
  }

  void pop() override {
    if (!isEmptyStack()) {
      stackTop--;
    } else
      std::cout << "Stack is empty cannot remove" << std::endl;
  }

  StackType<T>(int stackSize = 100) {
    if (stackSize <= 0) {
      std::cout << "The size of the array to hold the stack must be positive"
                << std::endl;

      std::cout << "Craeting an array of size 100 by defualt" << std::endl;
      stackSize = 100;
    }
    maxStackSize = stackSize;
    stackTop = 0;
    list = new T[maxStackSize];
  }

  StackType<T>(const StackType<T> &otherStack) {
    list = nullptr;
    copyStack(otherStack);
  }

  ~StackType<T>() { delete[] list; }

private:
  int maxStackSize;
  int stackTop;
  T *list;

  void copyStack(const StackType<T> &otherStack) {
    delete[] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new T[maxStackSize];

    for (int i = 0; i < stackTop; i++) {
      list[i] = otherStack.list[i];
    }
  }
};

#endif // !STACKTYPE_H
