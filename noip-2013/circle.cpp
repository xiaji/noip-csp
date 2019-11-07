#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void open_f() {
  freopen("circle.in", "r", stdin);
  freopen("circle.out", "w", stdout);
}

void close_f() {
  fclose(stdin);
  fclose(stdout);
}

ll quick_power(int a, int n, int mod) {
  ll res = 1, base = a % mod;
  while (n) {
    if (n & 1) res = (res * base) % mod;
    base = (base * base) % mod;
    n >>= 1;
  }
  return res % mod;
}