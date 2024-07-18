#ifndef QUEUE_H
#define QUEUE_H

template <typename T> class QueueADT {
public:
  virtual bool isEmptyQueue(void) const = 0;

  virtual bool isFullQueue(void) const = 0;

  // initialize queue to empty state -- it is like reset
  virtual void initializeQueue(void) = 0;

  virtual T front(void) const = 0;

  virtual T back(void) const = 0;

  virtual void addQueue(const T &newItem) = 0;

  virtual void deleteQueue() = 0;
};

#endif // !QUEUE_H
