#include<iostream>
using namespace std;
string s;

long long magic(int l, int r) {
  long long ans = 0;
  for (int i = l; i <= r; ++i) {
    ans = ans * 4 + s[i] - 'a' + 1;
  }
  return ans; 
}

int main() {
  cin >> s;
  int len = s.length();
  for (int i = 1; i < len; i++) {
    cout << magic(0, i) << endl;
  }
  return 0;
}