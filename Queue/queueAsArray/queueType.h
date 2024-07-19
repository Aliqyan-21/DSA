#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include "../queue.h"
#include <cassert>
#include <iostream>

template <typename T> class QueueType : public QueueADT<T> {
public:
  // overload assignment operator for copying the queue
  const QueueType<T> &operator=(const QueueType<T> &otherQueue) {
    if (this != &otherQueue) // avoid self copy
      copyQueue(otherQueue);
    return *this;
  }

  bool isEmptyQueue(void) const override { return count == 0; }

  bool isFullQueue(void) const override { return count == maxQueueSize; }

  void initializeQueue(void) override {
    queueFront = 0;
    queueBack = maxQueueSize - 1;
    count = 0;
  }

  T front() const override {
    assert(!isEmptyQueue());
    return list[queueFront];
  }

  T back() const override {
    assert(!isEmptyQueue());
    return list[queueBack];
  }

  void addQueue(const T &newItem) override {
    if (!isFullQueue()) {
      queueBack = (queueBack + 1) % maxQueueSize; // circular array
      count++;
      list[queueBack] = newItem;
    } else
      std::cout << "Cannot insert element in a full queue" << std::endl;
  }

  void deleteQueue() override {
    if (!isEmptyQueue()) {
      queueFront = (queueFront + 1) % maxQueueSize;
      count--;
    } else
      std::cout << "Cannot delete item from an empty queue" << std::endl;
  }

  // default constructor
  QueueType(int queueSize = 100) {
    if (queueSize <= 0) {
      std::cout << "The size of queue should be a positive integer"
                << std::endl;
      std::cout << "Initializing an array of size 100" << std::endl;
    }
    maxQueueSize = queueSize;
    queueFront = 0;
    queueBack = maxQueueSize - 1;
    count = 0;
    list = new T[maxQueueSize];
  }

  // copy constructor
  QueueType(const QueueType<T> &otherQueue) { copyQueue(otherQueue); }

  ~QueueType() { delete[] list; }

private:
  // max size of queue given by user; default 100
  int maxQueueSize;
  // for empty and full
  int count;

  int queueFront;
  int queueBack;

  T *list;

  void copyQueue(const QueueType<T> &otherQueue) {
    delete[] list;

    maxQueueSize = otherQueue.maxQueueSize;
    queueFront = otherQueue.queueFront;
    queueBack = otherQueue.queueBack;
    count = otherQueue.count;

    list = new T[maxQueueSize];

    for (int i = 0; i < count; i++) {
      list[i] = otherQueue.list[i];
    }
  }
};

#endif
