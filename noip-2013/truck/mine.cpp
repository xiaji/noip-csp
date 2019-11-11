#include <bits/stdc++.h>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
const int MXN = 1e5+10;
const int MXM = 5e5+10;
const int MXB = 1 << 20;
char buf[MXB], *p1 = buf, *p2 = buf;

struct IO {
  inline char gc() {
    return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, MXB, stdin), p1 == p2) ? EOF : *p1++;
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
}io;

int ancestor[MXN][31], cost[MXN][31];
//union-find method, they need rank (whether this rank can reuse? just try)

//adj vector array to store graph
vector<pair<int, int>> adj[]