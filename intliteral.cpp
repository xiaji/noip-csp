#include <cstdio>

int main() {
  unsigned short a = 0b10101010;
  printf("%hu\n", a);
  int b = 0123;
  printf("%d\n", b);
  unsigned long long d = 0xFFFFFFFFFFF;
  printf("%llu\n", d);
  unsigned int aa = 5464675;
  printf("Yabba %x!\n", aa);
  unsigned int bb = 69;
  printf("There are %u, %o leaves here.\n", bb, bb);
}
