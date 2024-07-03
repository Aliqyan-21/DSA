#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include "linkedList.h"

template <typename T> class OrderedLinkedList : public LinkedListType<T> {
public:
  bool search(const T &searchItem) const override {
    bool found = false;
    NodeType<T> *current = this->first;

    while (current != nullptr && !found) {
      if (current->info >= searchItem)
        found = true;
      else
        current = current->link;
    }
    if (found)
      return (current->info == searchItem); // test for equality
    return false;
  }

  void insert(const T &newItem) {
    NodeType<T> *current = nullptr;
    NodeType<T> *trailCurrent = nullptr;
    NodeType<T> *newNode = new NodeType<T>;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (this->first == nullptr) {
      this->first = this->last = newNode;
    } else {
      current = this->first;
      bool found = false;

      while (current != nullptr && !found) {
        if (current->info >= newItem)
          found = true;
        else {
          trailCurrent = current;
          current = current->link;
        }
      }

      if (current == this->first) {
        newNode->link = this->first;
        this->first = newNode;
      } else {
        trailCurrent->link = newNode;
        newNode->link = current;

        if (current == nullptr)
          this->last = newNode;
      }
    }
    this->count++;
  }

  void insertFirst(const T &newItem) override { insert(newItem); }
  void insertLast(const T &newItem) override { insert(newItem); }

  void deleteNode(const T &deleteItem) override {
    NodeType<T> *current = this->first;
    NodeType<T> *trailCurrent = nullptr;
    bool found = false;

    if (this->first == nullptr) {
      std::cout << "Cannot delete from an empty list." << std::endl;
      return;
    }

    while (current != nullptr && !found) {
      if (current->info >= deleteItem)
        found = true;
      else {
        trailCurrent = current;
        current = current->link;
      }
    }

    if (current == nullptr) {
      std::cout << "The item to be deleted is not in the list." << std::endl;
    } else {
      if (current->info == deleteItem) {
        if (this->first == current) {
          this->first = this->first->link;
          if (this->first == nullptr)
            this->last = nullptr;
        } else {
          trailCurrent->link = current->link;
          if (current == this->last)
            this->last = trailCurrent;
        }
        delete current;
        this->count--;
      } else {
        std::cout << "The item to be deleted is not in the list." << std::endl;
      }
    }
  }
};

#endif // ORDEREDLINKEDLIST_H
