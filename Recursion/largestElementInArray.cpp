#include <iostream>

int largest(const int list[], int lowerIndex, int upperIndex) {
  int max;

  if (lowerIndex == upperIndex)
    return list[lowerIndex];

  else {
    max = largest(list, lowerIndex + 1, upperIndex);

    if (max >= list[lowerIndex])
      return max;
    else
      return list[lowerIndex];
  }
}

int main(void) {
  int arr[10] = {23, 43, 35, 38, 67, 12, 76, 10, 34, 8};
  int mx = largest(arr, 0, 9);
  std::cout << mx << std::endl;
  return 0;
}
