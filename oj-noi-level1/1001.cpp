/* 1001
 * change fahrenheit to celsius
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double fah, cel;
  cin >> fah;
  cel = (fah - 32) * 5 / 9;
  // cout.precision(4);
  // cout.fill('0');
  cout << fixed << setprecision(4) << cel << endl;
  return 0;
}

