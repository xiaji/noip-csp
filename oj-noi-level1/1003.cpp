/*
 * guess number
 */
#include <iostream>
using namespace std;

int main() {
  int input;
  cin >> input;
  input *= 1001;
  input /= 7 * 11 * 13;
  cout << input;
  return 0;
}
