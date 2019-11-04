#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ifstream fin("data.in");
ofstream fout("mine.out");

double quick_power(double rate, int n) {
  double base = 1.0 + rate / 100;
  double res = 1.0;
  while (n != 0) {
    if (n & 1) res *= base;
    base *= base;
    // mistake: n /= 2
    // use bit manipulate, forget assign to n
    n >>= 1;
  }
  return res;
}

int main() {
  double r, x, p;
  double y;
  fin >> r >> x >> p;
  y = x * quick_power(r, p);
  fout << fixed << setprecision(2) << y << endl;
}