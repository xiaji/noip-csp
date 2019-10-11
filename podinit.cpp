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

void print_array(int nums[]) {
  for (int num : nums) {
    printf("%d ", num);
  }
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
  int arr1[] = {1, 2, 3};
  print_array(arr1);
  int arr2[5] = {1, 2, 3};
  print_array(arr2);
  int arr3[5] = {};
  print_array(arr3);
  int arr4[5];
  print_array(arr4);
}


