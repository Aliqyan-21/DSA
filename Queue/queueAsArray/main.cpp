#include "queueType.h"

int main(void) {
  QueueType<int> queue;
  QueueType<int> queue2;

  queue.addQueue(1);
  queue.addQueue(2);
  queue.addQueue(3);
  queue.addQueue(4);

  queue2 = queue;

  while (!queue.isEmptyQueue()) {
    std::cout << queue.front() << " ";
    queue.deleteQueue();
  }
  std::cout << std::endl;

  while (!queue2.isEmptyQueue()) {
    std::cout << queue2.front() << " ";
    queue2.deleteQueue();
  }
  std::cout << std::endl;

  return 0;
}
