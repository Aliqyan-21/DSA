#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include "../queue.h"
#include <cassert>
#include <iostream>

template <typename T> class NodeType {
public:
  T info;
  NodeType<T> *link;
};

template <typename T> class QueueType : public QueueADT<T> {
public:
  QueueType<T> &operator=(const QueueType<T> &otherQueue) {
    if (this != &otherQueue) {
      initializeQueue();
      copyQueue(otherQueue);
    }
    return *this;
  }

  bool isEmptyQueue() const override { return queueFront == nullptr; }

  // just because included as abstract function in ADT class
  // It can never be full as it is dynamic
  bool isFullQueue() const override { return false; }

  void initializeQueue() override {
    NodeType<T> *temp;

    while (queueFront != nullptr) {
      temp = queueFront;
      queueFront = queueFront->link;

      delete temp;
    }
    queueBack = nullptr;
  }

  T front() const override {
    assert(queueFront != nullptr);
    return queueFront->info;
  }

  T back() const override {
    assert(queueBack != nullptr);
    return queueBack->info;
  }

  void addQueue(const T &newItem) override {
    NodeType<T> *newNode = new NodeType<T>();
    newNode->info = newItem;
    newNode->link = nullptr;

    if (queueFront == nullptr) {
      // if initially the queue is empty
      queueFront = newNode;
      queueBack = newNode;
    } else {
      queueBack->link = newNode;
      // one up the queueBack
      queueBack = queueBack->link;
    }
  }

  void deleteQueue() override {
    if (!isEmptyQueue()) {
      NodeType<T> *temp = queueFront;
      queueFront = queueFront->link;
      delete temp;
      if (queueFront == nullptr)
        queueBack = nullptr;
    } else
      std::cout << "Cannot delete from an empty queue" << std::endl;
  }

  // default constructor
  QueueType() : queueFront(nullptr), queueBack(nullptr) {}

  // copy constructor
  QueueType(const QueueType<T> &otherQueue) { copyQueue(otherQueue); }

  ~QueueType() {
    NodeType<T> *temp;
    while (queueFront != nullptr) {
      temp = queueFront;
      queueFront = queueFront->link;
      delete temp;
    }
    queueBack = nullptr;
  }

private:
  // pointer to the front and back node of queue
  NodeType<T> *queueFront;
  NodeType<T> *queueBack;

  void copyQueue(const QueueType<T> &otherQueue) {
    if (!isEmptyQueue())
      initializeQueue();
    if (otherQueue.isEmptyQueue()) {
      queueFront = nullptr;
      queueBack = nullptr;
    } else {
      NodeType<T> *current = otherQueue.queueFront;
      while (current != nullptr) {
        addQueue(current->info);
        current = current->link;
      }
    }
  }
};

#endif // !QUEUETYPE_H
