#include <cstdio>

int main() {
  int x;
  scanf("%d", &x);
  int res = 0;
  for (int i = 0; i < x; ++i) {
    if (i * i % x == 1) {
      printf("%d ", i);
      ++res;
    }
  }
  printf("%d", res);
  return 0;
}
