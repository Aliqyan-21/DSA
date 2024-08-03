#include <iostream>

void shellSort(int arr[], int size) {
  // starting with large gap , then reduce it
  for (int gap = size / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < size; i++) {
      int temp = arr[i];
      int j;

      // shift the gap-sorted elements up until the correct location
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = gap;
    }
  }
}

int main(void) {
  int arr[] = {2, 1, 7, 21, 3, 7, 0, 19};

  shellSort(arr, 8);

  for (int i = 0; i < 8; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
