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

  inline void open() {
    freopen("truck.in", "w", stdin);
    freopen("truck.out", "r", stdout);
  }

  inline void close() {
    fclose(stdin);
    fclose(stdout);
  }
}io;

//union-find method, they need rank (whether this rank can reuse? just try)
int fa[MXN], deep[MXN];
struct union_find {
  int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
  }

  bool is_union(int x, int y) {
    return find(x) == find(y);
  }

  void unite(int x, int y) {
    int xfa = find(x);
    int yfa = find(y);
    if (xfa == yfa) return;
    if (deep[xfa] < deep[yfa]) {
      fa[xfa] = yfa;
    } else {
      fa[yfa] = xfa;
      if (deep[xfa] == deep[yfa]) deep[xfa]++;
    }
  }
}uf;

// find max spanning tree
struct Edge {
  int s, d, w;
  bool operator < (const Edge& tmp) const {
    return w > tmp.w;
  }
};

int n, m;

void kruskal(Edge* e, vector<pair<int, int> >* adj) {
  int cnt = 0;
  _rep(i, 0, m) {
    int u = e[i].s, v = e[i].d, w = e[i].w; 
    //int sfa = uf.find(u);
    //int dfa = uf.find(v);
    if (uf.is_union(u, v)) continue;
    fa[v] = u;
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
    cnt++;
    if (cnt >= n - 1) break;
  }
}

// adj vector array to store graph
// vector<pair<int, int> > adj[MXN];

int main() {
  io.open();
  n = io.read();
  m = io.read();
  Edge e[m];
  _rep(i, 0, m) {
    e[i].s = io.read();
    e[i].d = io.read();
    e[i].w = io.read();
  }
  sort(e, e + m);
  vector<pair<int, int> > adj[n + 1];
  kruskal(e, adj);
  io.close();
  return 0;
}


