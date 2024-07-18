#ifndef STACKTYPE_H
#define STACKTYPE_H

#include "../stack.h"
#include <iostream>

template <typename T> class NodeType {
public:
  T info;
  NodeType<T> *link;
};

template <typename T> class StackType : public Stack<T> {
public:
  const StackType<T> &operator=(const StackType<T> &otherStack) {
    if (this != &otherStack) {
      copyStack(otherStack);
    }
    return *this;
  }

  bool isEmptyStack() const override { return stackTop == nullptr; }

  bool isFullStack() const override {
    // can't be full as it is dynamic
    return false;
  }

  void initializeStack() override {
    NodeType<T> *temp; // to delete node
    while (stackTop != nullptr) {
      temp = stackTop;
      stackTop = stackTop->link;
      delete temp;
    }
  }

  void push(const T &newItem) override {
    NodeType<T> *newNode = new NodeType<T>;
    newNode->info = newItem;
    newNode->link = stackTop;
    stackTop = newNode;
  }

  T top() const override {
    if (!isEmptyStack()) {
      return stackTop->info;
    } else {
      std::cout << "Stack is empty, there are no elements to fetch"
                << std::endl;
      exit(1);
    }
  }

  void pop() override {
    NodeType<T> *temp;
    if (!isEmptyStack()) {
      temp = stackTop;
      stackTop = stackTop->link;
      delete temp;
    } else {
      std::cout << "Stack is empty, there are no elements to delete"
                << std::endl;
    }
  }

  StackType() { stackTop = nullptr; }

  StackType(const StackType<T> &otherStack) {
    stackTop = nullptr;
    copyStack(otherStack);
  }

  ~StackType() { initializeStack(); }

private:
  NodeType<T> *stackTop; // pointer to the stack

  void copyStack(const StackType<T> &otherStack) {
    NodeType<T> *newNode, *current, *last;
    if (!isEmptyStack())
      initializeStack();
    if (otherStack.stackTop == nullptr) {
      stackTop = nullptr;
    } else {
      current = otherStack.stackTop;
      stackTop = new NodeType<T>;

      stackTop->info = current->info;
      stackTop->link = nullptr;
      last = stackTop;
      current = current->link;

      while (current != nullptr) {
        newNode = new NodeType<T>;

        newNode->info = current->info;
        newNode->link = nullptr;
        last->link = newNode;
        last = newNode;
        current = current->link;
      }
    }
  }
};

#endif // !STACKTYPE_H
