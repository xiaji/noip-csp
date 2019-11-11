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

// union-find method, they need rank (whether this rank can reuse? just try)
// you can not use the same deep array, but you can clear its content. and restore new value
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

inline void kruskal(Edge* e, vector<pair<int, int> >* adj) {
  int cnt = 0;
  _rep(i, 0, m) {
    int u = e[i].s, v = e[i].d, w = e[i].w; 
    int f1 = uf.find(u);
    int f2 = uf.find(v);
    if (f1 == f2) continue;
    fa[f2] = f1;
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
    cnt++;
    if (cnt >= n - 1) break;
  }
}

// binary lifting find lca: anc[MXN][31], cost[MXN][31], deep[MXN]
void dfs(int* anc, int* cost, int root, int fno, vector<pair<int, int> >* v) {
  anc[root][0] = fno;
  deep[root] = deep[fno] + 1;
  _rep(i, 1, 31) {
    anc[root][i] = anc[anc[root][i - 1]][i - 1];
    cost[root][i] = min(cost[anc[root][i - 1]][i - 1], cost[root][i - 1]);
  }
  int sz = v[root].size();
  _rep(i, 0, sz) {
    int d = v[root][i].first;
    int w = v[root][i].second;
    if (d == fno) continue;
    cost[d][0] = w;
    dfs(anc, cost, d, root, v);
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
  _rep(i, 1, n + 1) {
    fa[i] = i;
    // for union_find, unite method
    deep[i] = 0;
  }
  sort(e, e + m);
  vector<pair<int, int> > adj[n + 1];
  kruskal(e, adj);
  int anc[n + 1][31], cost[n + 1][31];
  memset(anc, 0, sizeof(anc));
  memset(cost, 0, sizeof(cost));
  memset(deep, 0, sizeof(deep));
  io.close();
  return 0;
}


