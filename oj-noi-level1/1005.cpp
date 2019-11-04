#include <iostream>
#include <iomanip>
using namespace std;

double quick_power(double rate, int n) {
  double base = 1.0 + rate / 100;
  double res = 1.0;
  while (n != 0) {
    if (n & 1) res *= base;
    base *= base;
    n >> 1;
  }
  return res;
}

int main() {
  double r, x, p;
  double y;
  cin >> r >> x >> p;
  y = x * quick_power(r, p);
  cout << fixed << setprecision(2) << y << endl;
}