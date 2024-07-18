#include "../../LinkedLists/unorderLinkedList.h"
#include <stack>

// reversing the linked list without the use of recursion with stacks,
// Thus stack are used to remove recursion
int main(void) {
  UnorderedLinkedList<int> list;
  std::stack<int> st;

  list.insertLast(1);
  list.insertLast(2);
  list.insertLast(3);
  list.insertLast(4);

  NodeType<int> *first = list.firstNode();

  std::cout << "The Linked List: " << std::endl;
  list.print();

  while (first != nullptr) {
    st.push(first->info);
    first = first->link;
  }

  std::cout << "The linked list printed in reverse: " << std::endl;
  while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
  }
  std::cout << std::endl;

  return 0;
}
