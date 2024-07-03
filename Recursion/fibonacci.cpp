#include <iostream>

int defFibonacci(int n) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 1;
  else
    return defFibonacci(n - 1) + defFibonacci(n - 2);
}

int fibonacci(int a, int b, int n) {
  if (n == 1)
    return a;
  if (n == 2)
    return b;
  else
    return fibonacci(a, b, n - 1) + fibonacci(a, b, n - 2);
}

// 0 1 1 2 3 5
int main(void) {
  int n = 4;

  int fib = fibonacci(2, 3, n);

  int dfib = defFibonacci(n);

  std::cout << fib << std::endl;

  std::cout << dfib << std::endl;

  return 0;
}
