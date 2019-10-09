#include <cstddef>
#include <cstdio>

int main() {
  char english[] = "A book holds a house of gold";
  //char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
  printf("English : %s;\n", english);
  //printf("Chinese : %S.\n", chinese);
  char alphabet[27];
  for (int i = 0; i < 26; i++) {
    alphabet[i] = i + 97;
  }
  //alphabet[26] = 0;
  printf("%s\n", alphabet);
  for (int i = 0; i < 26; i++) {
    alphabet[i] = i + 65;
  }
  printf("%s\n", alphabet);
  return 0;
}
