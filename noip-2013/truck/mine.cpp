#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;
const int MXN = 1e5 + 10;
const int MXM = 5e5 + 10;
const int MXB = 1 << 20;
char buf[MXB], *p1 = buf, *p2 = buf;
char pbuf[MXB], *pp = pbuf;

struct IO
{
  inline char gc()
  {
    return (p1 == p2) && (p2 = (p1 = buf) + fread(buf, 1, MXB, stdin), p1 == p2) ? EOF : *p1++;
  }

  inline int read()
  {
    int x = 0, sign = 1;
    char ch = gc();
    while (!isdigit(ch))
    {
      if (ch == '-')
        sign = -1;
      ch = gc();
    }
    while (isdigit(ch))
    {
      x = (x << 3) + (x << 1) + ch - '0';
      ch = gc();
    }
    return x * sign;
  }

  inline void push(const char &ch)
  {
    if (pp - pbuf == MXB)
      fwrite(pbuf, 1, MXB, stdout), pp = pbuf;
    *pp++;
  }

  inline void write(int x)
  {
    static int s[35];
    int start = 0;
    do
    {
      s[start++] = x % 10;
      x /= 10;
    } while (x);
    while (start)
      push(s[--start] + '0');
  }

  inline void open()
  {
    freopen("truck.in", "r", stdin);
    freopen("truck.out", "w", stdout);
  }

  inline void close()
  {
    fclose(stdin);
    fclose(stdout);
  }
} io;

// union-find method, they need rank (whether this rank can reuse? just try)
// you can not use the same deep array, but you can clear its content. and restore new value
int fa[MXN], _rank[MXN];
struct union_find
{
  int find(int x)
  {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
  }

  bool is_union(int x, int y)
  {
    return find(x) == find(y);
  }

  void unite(int x, int y)
  {
    int xfa = find(x);
    int yfa = find(y);
    if (xfa == yfa)
      return;
    if (_rank[xfa] < _rank[yfa])
    {
      fa[xfa] = yfa;
    }
    else
    {
      fa[yfa] = xfa;
      if (_rank[xfa] == _rank[yfa])
        _rank[xfa]++;
    }
  }
} uf;

// find max spanning tree
struct Edge
{
  int s, d, w;
  bool operator<(const Edge &tmp) const
  {
    return w > tmp.w;
  }
};

int n, m;

inline void kruskal(Edge *e, vector<pair<int, int> > *adj)
{
  int cnt = 0;
  _rep(i, 0, m)
  {
    int u = e[i].s, v = e[i].d, w = e[i].w;
    int f1 = uf.find(u);
    int f2 = uf.find(v);
    if (f1 == f2)
      continue;
    fa[f2] = f1;
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
    cnt++;
    if (cnt >= n - 1)
      break;
  }
}

// binary lifting find lca: anc[MXN][31], cost[MXN][31], deep[MXN]
// int MXLOG = ceil(log2(MXN));
int anc[MXN][31], cost[MXN][31];
int mx_log;
void dfs(int root, int fno, vector<pair<int, int> > *v, int *deep)
{
  anc[root][0] = fno;
  deep[root] = deep[fno] + 1;
  _rep(i, 1, mx_log)
  {
    anc[root][i] = anc[anc[root][i - 1]][i - 1];
    cost[root][i] = min(cost[anc[root][i - 1]][i - 1], cost[root][i - 1]);
  }
  int sz = v[root].size();
  _rep(i, 0, sz)
  {
    int d = v[root][i].first;
    int w = v[root][i].second;
    if (d == fno)
      continue;
    //anc[d][0] = root;
    cost[d][0] = w;
    dfs(d, root, v, deep);
  }
}
const int INF = 0x3f3f3f3f;
inline int cmp(int a, int b, int c)
{
  int min = a;
  if (min > b)
    min = b;
  if (min > c)
    min = c;
  return min;
}
int lca(int x, int y, int *deep)
{
  if (deep[x] < deep[y])
    swap(x, y);
  int dist = deep[x] - deep[y], ans = INF;
  while (dist)
  {
    int raise = log2(dist);
    x = anc[x][raise];
    ans = min(ans, cost[x][raise]);
    dist -= raise;
  }
  if (x == y)
    return ans;
  for (int j = mx_log; j >= 0 && (x != y); --j)
  {
    if (anc[x][j] != anc[y][j])
    {
      ans = cmp(ans, cost[x][j], cost[y][j]);
      x = anc[x][j];
      y = anc[y][j];
    }
  }
  return cmp(ans, anc[x][0], anc[y][0]);
}

// adj vector array to store graph
// vector<pair<int, int> > adj[MXN];

int main()
{
  io.open();
  n = io.read();
  m = io.read();
  Edge e[m];
  _rep(i, 0, m)
  {
    e[i].s = io.read();
    e[i].d = io.read();
    e[i].w = io.read();
  }
  int deep[n + 1];
  _rep(i, 1, n + 1)
  {
    fa[i] = i;
    // for union_find, unite method
    deep[i] = 0;
  }
  sort(e, e + m);
  vector<pair<int, int> > adj[n + 1];
  kruskal(e, adj);
  memset(anc, 0, sizeof(anc));
  memset(cost, 0, sizeof(cost));
  memset(deep, 0, sizeof(deep));
#ifdef DEBUG
  _rep(i, 1, n + 1)
  {
    printf("start : %d\n", i);
    for (vector<pair<int, int> >::iterator it = adj[i].begin();
         it != adj[i].end(); ++it)
    {
      printf("destination: %d, weight : %d\n", it->first, it->second);
    }
  }
#endif
  mx_log = ceil(log2(MXN));
  dfs(1, 0, adj, deep);
#ifdef DEBUG
  _rep(i, 1, n + 1)
  {
    printf("node : %d\n", i);
    printf("deep : %d\n", deep[i]);
    _rep(j, 0, ceil(log2(n)))
    {
      printf("%d th ancestor is %d and cost is %d\n",
             j, anc[i][j], cost[i][j]);
    }
  }
#endif
  int q = io.read();
  _rep(i, 0, q)
  {
    int x = io.read();
    int y = io.read();
    if(!uf.is_union(x, y)) {
      printf("%d", -1);
      continue;
    }
    lca(x, y, deep);
  }
  io.close();
  return 0;
}
