#include <iostream>
using namespace std;

// n different balls, and m same box
// n >= m
// could use memo to store the res of stirling(n, m)
int stirling(int n, int m) {
  if (n < m) {
    return 0;
  }
  if (n == m || m == 1) {
    return 1;
  }
  return m * stirling(n - 1, m) + stirling(n - 1, m - 1);
}


int main() {
  int res = stirling(4, 3);
  cout << res << endl;
  return 0;
}