#include "queueType.h"

int main(void) {
  QueueType<int> queue;
  int x, y;

  queue.initializeQueue();

  x = 4;
  y = 5;

  queue.addQueue(x);
  queue.addQueue(y);

  x = queue.front();
  queue.deleteQueue();
  queue.addQueue(x + 5);
  queue.addQueue(16);
  queue.addQueue(x);
  queue.addQueue(y - 3);

  QueueType<int> queue2;
  queue2 = queue;

  std::cout << "Queue Elements: " << std::endl;

  while (!queue.isEmptyQueue()) {
    std::cout << queue.front() << " ";
    queue.deleteQueue();
  }
  std::cout << std::endl;

  std::cout << "Queue2(copied from queue) Elements: " << std::endl;

  while (!queue2.isEmptyQueue()) {
    std::cout << queue2.front() << " ";
    queue2.deleteQueue();
  }
  std::cout << std::endl;

  return 0;
}
