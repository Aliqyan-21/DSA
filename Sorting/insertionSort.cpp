#include <iostream>

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int tmp = arr[i];
    int loc;
    for (loc = i - 1; loc >= 0; loc--) {
      if (arr[loc] > tmp)
        arr[loc + 1] = arr[loc];
      else
        break;
    }
    arr[loc + 1] = tmp;
  }
}

int main(void) {
  int arr[] = {2, 1, 7, 21, 3, 7, 0, 19};
  insertionSort(arr, 8);

  for (int i = 0; i < 8; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
