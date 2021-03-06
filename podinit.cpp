#include <cstdio>

struct PodStruct {
  int a;
  char b[256];
  bool c;
};

struct Test {
  int a;
};

void initialize(PodStruct pod) {
  printf("a : %d, b : %s, c : %d\n", pod.a, pod.b, pod.c);
}

void print_array(int nums[], int size) {
  // range-for does not work for pointers
  /*for (int num : nums) {
    printf("%d ", num);
  }*/
  for (int i = 0; i < size; ++i) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}

void print_arr(int* nums, int x, int y) {
  for (int i = 0; i != x; ++i) {
    for (int j = 0; j != y; ++j) {
       printf("%d ", nums[i * x +j]);
    }
  }
  printf("\n");
}

int main() {
  Test test{9};
  printf("test a : %d\n", test.a);
  PodStruct init1{};
  initialize(init1);
  PodStruct init2 = {};
  initialize(init2);
  PodStruct init3{42, "hello"};
  initialize(init3);
  PodStruct init4{42, "hello", true};
  initialize(init4);
  int arr1[]{1, 2, 3};
  print_array(arr1, 3);
  int arr2[5]{1, 2, 3};
  print_array(arr2, 5);
  int arr3[5]{};
  print_array(arr3, 5);
  int arr4[5];
  print_array(arr4, 5);
  int arr5[3][2]{{1, 2}, {4, 5}, {6, 7}};
  print_arr(arr5[0], 3, 2);
}


