#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define _rep(i, a, b) for(int i = (a); i < (b); ++i)

using namespace std;
const int MXN = 5e4+7;
std::vector<int> v[MXN];
std::vector<int> w[MXN];

int fa[MXN][31], cost[MXN][31], deep[MXN];
int n, m;

void dfs(int root, int fno) {
  fa[root][0] = fno;
  deep[root] = deep[fa[root][0]] + 1;
  _rep(i, 1, 31) {
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
    cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
  }
  int sz = v[root].size();
  _rep(i, 0, sz) {
    if (v[root][i] == fno) continue;
    // u:root, v:v[root].get(i), 0:parent, cost is from u to v weight
    cost[v[root][i]][0] = w[root][i];
    dfs(v[root][i], root);
  }
}

int lca(int x, int y) {
  if (deep[x] < deep[y]) swap(x, y);
  int tmp = deep[x] - deep[y], ans = 0;
  for (int j = 0; tmp; ++j, tmp >>= 1)
    if (tmp & 1) ans += cost[x][j], x = fa[x][j];
  if (x == y) return x;
  for (int j = 30; j >= 0 && (x != y); --j) {
    if (fa[x][j] != fa[y][j]) {
      ans += cost[x][j] + cost[y][j];
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  ans += cost[x][0] + cost[y][0];
  return ans;
}

int main() {
  int a, b, c;
  memset(fa, 0, sizeof(fa));
  memset(cost, 0, sizeof(cost));
  memset(deep, 0, sizeof(deep));
  scanf("%d", n);
  _rep(i, 1, n) {
    scanf("%d%d%d", &a, &b, &c);
    // node from 0 to n - 1
    ++a, ++b;
    v[a].push_back(b);
    v[b].push_back(a);
    w[a].push_back(c);
    w[b].push_back(c);
  }
  dfs(1, 0);
  scanf("%d", &m);
  _rep(i, 0, m) {
    scanf("%d%d", &a, &b);
    ++a, ++b;
    int res = lca(a, b);
    printf("%d\n", res);
  }
  return 0;
}