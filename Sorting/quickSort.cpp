#include <iostream>
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int partition(int arr[], int first, int last) {
  int pivot;

  int index, smallIndex;

  swap(arr[first], arr[(first + last) / 2]);

  pivot = arr[first];
  smallIndex = first;

  for (index = first + 1; index <= last; index++) {
    if (arr[index] < pivot) {
      smallIndex++;
      swap(arr[smallIndex], arr[index]);
    }
  }
  swap(arr[first], arr[smallIndex]);
  return smallIndex;
}

void quickSort(int arr[], int first, int last) {
  int pivotLoc;

  if (first < last) {
    pivotLoc = partition(arr, first, last);
    quickSort(arr, first, pivotLoc - 1);
    quickSort(arr, pivotLoc + 1, last);
  }
}

int main(void) {
  int arr[10] = {1, 21, 3, 56, 32, 12, 2, 0, 1, 3};

  quickSort(arr, 0, 9);

  for (int i = 0; i < 10; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
