#include <iostream>

void moveDisks(int count, int needle1, int needle3, int needle2) {
  if (count > 0) {
    moveDisks(count - 1, needle1, needle2, needle3);
    std::cout << "Move " << count << " from " << needle1 << " to " << needle3
              << "." << std::endl;
    moveDisks(count - 1, needle2, needle3, needle1);
  }
}

int main(void) {
  int n;
  std::cin >> n;
  moveDisks(n, 1, 3, 2);
  return 0;
}
