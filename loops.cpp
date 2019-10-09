#include <cstddef>
#include <cstdio>

int main() {
  // if max = -1 and unsigned long array contains negative nums
  // max = 18446744073709551615%
  // only change max = 0, do not edit negative val of nums array
  // it still returns 18446744073709551606%
  unsigned long max = 0;
  unsigned long nums[] = {5,7,8,8,0};
  for (size_t i = 0; i < 5; i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  unsigned long arr[] = {54325, 6, 7, 87, 8};
  for (unsigned long val : arr) {
    if (val > max) {
      max = val;
    }
  }
  size_t n_elements = sizeof(arr) / sizeof(unsigned long);
  printf("The number of elements in arr is %zd.\n", n_elements);
  printf("The max value is %lu", max);
  return max;
}
