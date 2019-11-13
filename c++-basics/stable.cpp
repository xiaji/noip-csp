#include <bits/stdc++.h>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
const int MXN = 1e5 + 10;
const int MXM = 1e6 + 10;
const int MXB = 1 << 20;
const int MXLOG = 31;
int logn[MXN];
char buf[MXB], *p1 = buf, *p2 = buf;
char pbuf[MXB], *pp = pbuf;

struct IO
{
  inline char gc() {
    if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MXB, stdin);
    return p1 == p2 ? ' ' : *p1++;
  }

  inline int read() {
    int x = 0, sign = 1;
    char ch = gc();
    while (!isdigit(ch)) {
      if (ch == '-') sign = -1;
      ch = gc();
    }
    while (isdigit(ch)) {
      x = (x << 3) + (x << 1) + ch - '0';
      ch = gc();
    }
    return x * sign;
  }

  inline void push(const char& ch) {
    if (pp - pbuf == MXB) {
      fwrite(pbuf, 1, MXB, stdout);
      pp = pbuf;
    }
    *pp++ = ch;
  }

  inline void write(int x) {
    static int st[35];
    int top = 0;
    do {
      st[top++] = x % 10;
      x /= 10;
    } while (x);
    while(top) push(st[--top] + '0');
  }
} io;

int f[MXN][MXLOG];
int n, m;

inline void pre() {
  logn[1] = 0;
  logn[2] = 1;
  _rep(i, 3, MXN) {
    logn[i] = logn[i >> 1] + 1;
  }
}

inline void init() {
  _rep(j, 1, MXLOG) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
}

inline int search(int x, int y) {
  int s = logn[y - x + 1];
  int res =  max(f[x][s], f[y - (1 << s) + 1][s]);
  io.write(res);
}

int main() {
  n = io.read();
  m = io.read();
  _rep(i, 1, n + 1) {
    f[i][0] = io.read();
  }
  pre();
  init();
  _rep(i, 0, m) {
    int x = io.read();
    int y = io.read();
    int s = logn[y - x + 1];
    int res =  max(f[x][s], f[y - (1 << s) + 1][s]);
    printf("%d\n", res);
  }
  return 0;
}
