#include <iostream>
#include <fstream>
#include <iomanip>
const double eps = 1e-8;
#define _rep(i, a, b) for (int i = (a); (b) - i > eps; ++i)
using namespace std;

ifstream fin("data.out");
ofstream fout("std.out");

int main() {
  double r, x, p;
  double y = 1.0;
  fin >> r >> x >> p;
  _rep(i, 0, p) {
    y *= (1 + r / 100);
  }
  /*for (int i = 0; p - i > eps; i++) {
    y *= (1 + r / 100);
  }*/
  y *= x;
  fout << fixed << setprecision(2) << y << endl;
}