#include <cstdio>

int main() {
  double an = 6.03264523e23;
  printf("## test: %le %lf %lg.\n", an, an, an);
  float hp = 0.75;
  printf("float test: %e %f %g.\n", hp, hp, hp);
}
