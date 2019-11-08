#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define _rep(i, a, b) for(int i = (a); i < (b); ++i)

using namespace std;
typedef long long ll;

const int MAXN = 100010;
const int MOD = 99999997;
int n, c[MAXN], bits[MAXN];

struct node {
  int val, id;
  bool operator<(const node& A) const {
    return (val < A.val);
  }
}a[MAXN], b[MAXN];

namespace bit {
  ll lowbit(int x) {
    return x & (-x);
  }

  void add(int x) {
    while (x < n) {
      bits[x]++;
      x += lowbit(x);      
    }
  }

  ll get_sum(int i) {
    return sum(n - 1) - sum(i);
  }

  ll sum(int i) {
    ll sum = 0;
    while (i >= 0) {
      sum += bits[i];
      i -= lowbit(i);
    }
    return sum;
  }
}

namespace io_f {
  void open() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
  }

  void close() {
    fclose(stdin);
    fclose(stdout);
  }

  inline int read() {
    int x = 0, f = 1;
    char ch = 0;
    while (!isdigit(ch)) {
      if (ch == '-') f = -1;
      ch = getchar();
    }
    while (isdigit(ch)) {
      x = (x << 3) + (x << 1) + (ch - '0');
      ch = getchar();
    }
    return x * f;
  }
}

using namespace bit;
using namespace io_f;

void init() {
  n = read();
  _rep(i, 0, n) {
    a[i].val = read();
    a[i].id = i;
  }
  _rep(i, 0, n) {
    b[i].val = read();
    b[i].id = i;
  }
}

int main() {
  open();
  init();
  sort(a, a + n);
  sort(b, b + n);
  _rep(i, 0, n) {
    c[a[i].id] = b[i].id;
    bits[i] = 0;
  }
  ll ans = 0;
  //bits[0] = 0;  
  _rep(i, 0, n) {
    ans = (ans + get_sum(c[i])) % MOD;
    add(i);
  }
  printf("%lld", ans);
  close();
  return 0;
}
