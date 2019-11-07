#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

// recursion method
ll quick_power(int a, int n, int mod) {
  if (n == 0) {
    return 1 % mod;
  }
  ll res = quick_power(a, n >> 1, mod);
  res = (res * res) % mod;
  if (n & 1) {
    res = (res * a) % mod;
  }
  return res;
}

// iteration method
ll qpower(int a, int n, int mod) {
  ll res = 1, base = a % mod;
  while (n) {
    if (n & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    n >>= 1;
  }
  return res % mod;
}


int main() {
  return 0;
}