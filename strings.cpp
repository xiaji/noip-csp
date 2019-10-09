#include <cstddef>
#include <cstdio>

int main() {
  char english[] = "A book holds a house of gold";
  char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
  printf("English : %s;\n", english);
  printf("Chinese : %S.\n", chinese);
  return 0;
}
