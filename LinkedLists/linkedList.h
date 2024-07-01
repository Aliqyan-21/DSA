#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class NodeType {
public:
  T info;
  NodeType<T> *link;
};

template <typename T>
class LinkedListIterator {
private:
  NodeType<T> *current;

public:
  LinkedListIterator() : current(nullptr) {}
  LinkedListIterator(NodeType<T> *ptr) : current(ptr) {}

  T operator*() const { return current->info; }
  LinkedListIterator<T> &operator++() {
    current = current->link;
    return *this;
  }
  bool operator==(const LinkedListIterator<T> &right) const { return current == right.current; }
  bool operator!=(const LinkedListIterator<T> &right) const { return current != right.current; }
};

template <typename T>
class LinkedListType {
protected:
  int count;
  NodeType<T> *first;
  NodeType<T> *last;

private:
  void copyList(const LinkedListType<T> &otherList) {
    NodeType<T> *newNode;
    NodeType<T> *current;

    if (first != nullptr)
      destroyList();

    if (otherList.first == nullptr) {
      first = last = nullptr;
      count = 0;
    } else {
      current = otherList.first;
      count = otherList.count;

      first = new NodeType<T>;
      first->info = current->info;
      first->link = nullptr;
      last = first;
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

public:
  LinkedListType() : first(nullptr), last(nullptr), count(0) {}
  LinkedListType(const LinkedListType<T> &otherList) : first(nullptr), last(nullptr), count(0) {
    copyList(otherList);
  }
  ~LinkedListType() { destroyList(); }

  const LinkedListType<T> &operator=(const LinkedListType &otherList) {
    if (this != &otherList) {
      copyList(otherList);
    }
    return *this;
  }

  void initializeList() { destroyList(); }
  bool isEmptyList() const { return first == nullptr; }
  void print() const {
    NodeType<T> *current = first;
    while (current != nullptr) {
      std::cout << current->info << " ";
      current = current->link;
    }
    std::cout << std::endl;
  }
  int length() const { return count; }
  void destroyList() {
    NodeType<T> *temp;
    while (first != nullptr) {
      temp = first;
      first = first->link;
      delete temp;
    }
    last = nullptr;
    count = 0;
  }

  T front() const {
    if (first == nullptr) {
      throw std::underflow_error("List is empty");
    }
    return first->info;
  }

  T back() const {
    if (last == nullptr) {
      throw std::underflow_error("List is empty");
    }
    return last->info;
  }

  virtual bool search(const T &searchItem) const = 0;
  virtual void insertFirst(const T &newItem) = 0;
  virtual void insertLast(const T &newItem) = 0;
  virtual void deleteNode(const T &deleteItem) = 0;

  LinkedListIterator<T> begin() const { return LinkedListIterator<T>(first); }
  LinkedListIterator<T> end() const { return LinkedListIterator<T>(nullptr); }
};

#endif // LINKEDLIST_H
