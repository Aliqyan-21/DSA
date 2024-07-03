#include <iostream>

void decToBin(int num, int base) {
  if(num == 0) return;
    decToBin(num/base, base);
    std::cout << num%2;
}

int main(void) {
  int n = 13;
  int base = 2;
  decToBin(n, base);
  std::cout << std::endl;
  return 0;
}
