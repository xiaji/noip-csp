#include <cstdio>

union Variant {
  char string[10];
  int integer;
  double floating_point;
};

int main() {
  Variant v;
  v.integer = 42;
  printf("The utimate answer: %d\n", v.integer);
  v.floating_point = 2.71245454564;
  printf("The floating num is %f\n", v.floating_point);
  printf("after seting floating point val, integer is %d\n", v.integer);
  //char arr[] = "dfewgewt";
  //v.string = arr;
  //printf("The string is %s\n", v.string);
  printf("After setting string, the float is %f, the integer is %d\n", 
      v.floating_point, v.integer);
  return 0;
}
