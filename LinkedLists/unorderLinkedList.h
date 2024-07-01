#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

#include "linkedList.h"

template <typename T>
class UnorderedLinkedList : public LinkedListType<T> {
public:
  bool search(const T &searchItem) const override {
    NodeType<T> *current = this->first;
    while (current != nullptr) {
      if (current->info == searchItem)
        return true;
      current = current->link;
    }
    return false;
  }

  void insertFirst(const T &newItem) override {
    NodeType<T> *newNode = new NodeType<T>;
    newNode->info = newItem;
    newNode->link = this->first;
    this->first = newNode;
    this->count++;

    if (this->last == nullptr)
      this->last = newNode;
  }

  void insertLast(const T &newItem) override {
    NodeType<T> *newNode = new NodeType<T>;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (this->first == nullptr) {
      this->first = this->last = newNode;
    } else {
      this->last->link = newNode;
      this->last = newNode;
    }
    this->count++;
  }

  void deleteNode(const T &deleteItem) override {
    NodeType<T> *current = this->first;
    NodeType<T> *trailCurrent = nullptr;

    if (this->first == nullptr) {
      std::cout << "Cannot delete from an empty list." << std::endl;
      return;
    }

    if (this->first->info == deleteItem) {
      current = this->first;
      this->first = this->first->link;
      this->count--;
      if (this->first == nullptr)
        this->last = nullptr;
      delete current;
    } else {
      bool found = false;
      trailCurrent = this->first;
      current = trailCurrent->link;

      while (current != nullptr && !found) {
        if (current->info != deleteItem) {
          trailCurrent = trailCurrent->link;
          current = current->link;
        } else {
          found = true;
        }
      }

      if (found) {
        trailCurrent->link = current->link;
        this->count--;
        if (current == this->last)
          this->last = trailCurrent;
        delete current;
      } else {
        std::cout << "The item to be deleted is not found in the list." << std::endl;
      }
    }
  }
};

#endif // UNORDEREDLINKEDLIST_H
