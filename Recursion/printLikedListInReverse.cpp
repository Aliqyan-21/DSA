#include "../LinkedLists/linkedList.h"
#include <iostream>

template <typename T> void reversePrint(NodeType<T> *current) {
  if (current != nullptr) {
    reversePrint(current->link);
    std::cout << current->info << std::endl;
  }
}
