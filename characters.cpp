#include<cstdio>

int main() {
  char a = \u0041;
  char32_t mug = U'\U0001F37A';
  printf("a is right ? %c.", a);
  printf("mug is %lc.", mug);
}
