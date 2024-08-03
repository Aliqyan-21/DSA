#include <iostream>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < (size - 1) - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main(void) {
  int arr[10] = {1, 21, 3, 56, 32, 12, 2, 0, 1, 3};

  int size = sizeof(arr) / sizeof(int);

  bubbleSort(arr, size);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
