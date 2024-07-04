#ifndef STACK_H
#define STACK_H

template <typename T> class Stack {
public:
  virtual void initializeStack() = 0;

  virtual bool isEmptyStack() const = 0;

  virtual bool isFullStack() const = 0;

  virtual void push(const T &newItem) = 0;

  virtual T top() const = 0;

  virtual void pop() = 0;
};

#endif // !STACK_H
