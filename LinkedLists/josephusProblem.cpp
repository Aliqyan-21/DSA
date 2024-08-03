#include <iostream>
using namespace std;

class Node {
public:
  int value;
  Node *next;

  // Constructor to initialize the node with a given value
  Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
  Node *head;
  Node *tail;

  void insertAtEnd(int value) {
    Node *newNode = new Node(value);

    if (head == NULL) {
      head = newNode;
    } else {
      tail->next = newNode;
    }

    // Set newNode as the tail
    tail = newNode;

    // Set next of tail to head
    tail->next = head;
  }

  int solveJosephus() {
    Node *current = head;
    Node *tmp = current;
    while (current->next != current) {
      Node *tmp = current->next->next;
      if (current->next == head) {
        head = tmp;
      }
      current->next = tmp;
      current = current->next;
    }
    return current->value;
  }

  // 1 - 2 - 3 - 4 - 5
};

int main() {
  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;

    LinkedList *list = new LinkedList();
    for (int i = 1; i <= n; i++) {
      list->insertAtEnd(i);
    }
    cout << list->solveJosephus() << '\n';
  }
}
