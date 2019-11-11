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
int a, b, c;

void dfs(int root, int fno) {
  fa[root][0] = fno;
  deep[root] = deep[fa[root][0]] + 1;
  _rep(i, 1, 31) {
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
    cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
  }
}