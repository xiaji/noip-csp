/*
 * cal triangle area: given three sides, to find the area
 * using helen theory
 * p = (a + b + c) / 2
 * area = sqrt(p * (p - a) * (p - b) * (p - c));
 * sqrt((a + b + c) * (b + c - a) * (a + c - b) * (a + b - c)) / 4
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
  double a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;
  // double p = (a + b + c) / 2.0;
  // double area = sqrt(p * (p - a) * (p - b) * (p - c));
  double area = sqrt((a + b + c) * (a + b - c) * (b + c - a) * (a + c - b)) / 4;
  cout << fixed << setprecision(4) << area << endl;
  return 0;
}
