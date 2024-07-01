#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename T> class NodeType {
  T info;
  NodeType<T> *next;
  NodeType<T> *back;
};

template <typename T> class DoublyLinkedList {
private:
  void copyList(const DoublyLinkedList<T> &otherList) {
    NodeType<T> *newNode;
    NodeType<T> *current;

    if (first != nullptr)
      destroy();

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

protected:
  NodeType<T> *first;
  NodeType<T> *last;
  int count;

public:
  const DoublyLinkedList<T> &operator=(const DoublyLinkedList<T> &otherList) {
    copyList(otherList);
  }

  void initializeList() { destroy(); }

  bool isEmptyList() const { return first == nullptr; }

  void destroy() {
    NodeType<T> *temp;
    while (first != nullptr) {
      temp = first;
      first = first->next;
      delete temp;
    }
    last = nullptr;
    count = 0;
  }

  void print() const {
    NodeType<T> *current = first;
    while (current != nullptr) {
      std::cout << current->info << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  void reversePrint() const {
    NodeType<T> *current = last;
    while (current != nullptr) {
      std::cout << current->info << " ";
      current = current->back;
    }
    std::cout << std::endl;
  }

  int length() const { return count; }

  int front() const {
    if (first == NULL)
      std::cout << "The list is empty" << std::endl;
    else
      return first->info;
  }
  int back() const {
    if (last == NULL)
      std::cout << "The list is empty" << std::endl;
    else
      return last->info;
  }

  bool search(const T &searchItem) const {
    NodeType<T> *current = first;
    bool found;

    while (current != nullptr) {
      if (current->info >= searchItem)
        found = true;
      else
        current = current->next;
    }
    if (found)
      return (current->info == searchItem); // test for equality
    else
      return found;
  }

  void insert(const T &newItem) {
    NodeType<T> *current;
    NodeType<T> *trailCurrent;
    NodeType<T> *newNode;
    bool found;

    newNode = new NodeType<T>;
    newNode->info = newItem;
    newNode->next = nullptr;
    newNode->back = nullptr;

    // case 1
    if (first == nullptr) {
      first = newNode;
      last = newNode;
      count++;
    } else {
      current = first;
      found = false;
      while (current != nullptr && !found) {
        if (current->info >= newItem)
          found = true;
        else {
          trailCurrent = current;
          current = current->next;
        }
      }
      // case 2
      if (current == first) {
        newNode->next = first;
        first->back = current;
        first = newNode;
        count++;
      } else {
        if (current != nullptr) {
          newNode->back = trailCurrent;
          newNode->next = current;
          trailCurrent->next = newNode;
          current->back = newNode;
        } else {
          trailCurrent->next = newNode;
          newNode->back = trailCurrent;
          last = newNode;
        }
        count++;
      }
    }
  }

  void deleteNode(const T &deleteItem) {
    NodeType<T> *current;
    NodeType<T> *trailCurrent;
    bool found;

    if (first == nullptr)
      std::cout << "Cannot delete item from empty list" << std::endl;
    else if (first->info == deleteItem) {
      current = first;
      first = first->next;
      delete current;
      count--;
    } else {
      current = first;
      found = false;

      while (current != nullptr) {
        if (current->info >= deleteItem)
          found = true;
        else {
          current = current->next;
        }
      }
      if (current == nullptr)
        std::cout << "The item to be deleted is not found in the list"
                  << std::endl;
      else if (current->info == deleteItem) {
        trailCurrent = current->back;
        trailCurrent->next = current->next;
        if (current->next != nullptr)
          current->next->back = trailCurrent;
        if (current == last)
          last = trailCurrent;
        delete current;
        count--;
      } else
        std::cout << "The item to be deleted is not found in the list"
                  << std::endl;
    }
  }

  DoublyLinkedList() {
    first = nullptr;
    last = nullptr;
    count = 0;
  }

  DoublyLinkedList(const DoublyLinkedList<T> &otherList);

  ~DoublyLinkedList();
};

#endif // !DOUBLYLINKEDLIST_H
