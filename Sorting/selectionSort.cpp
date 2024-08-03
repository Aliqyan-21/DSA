#include <iostream>

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int minLocation(int arr[], int first, int last) {
  int minIndex;
  minIndex = first;
  for (int i = first + 1; i < last; i++) {
    if (arr[i] < arr[minIndex])
      minIndex = i;
  }
  return minIndex;
}

void selectionSort(int arr[], int first, int last) {
  int minIndex;

  for (int i = first; i < last; i++) {
    minIndex = minLocation(arr, i, last);
    swap(arr[i], arr[minIndex]);
  }
}

int main(void) {
  int arr[10] = {1, 21, 3, 56, 32, 12, 2, 0, 1, 3};
  selectionSort(arr, 0, 10);

  for (int i = 0; i < 10; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
