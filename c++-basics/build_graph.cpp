#include <iostream>
#define _rep(i, a, b) for(int i = (a); i < (b); ++i)

using namespace std;
const int MAX_N = 100;
const int MAX_M = 10010;
const int INF = 0x3f3f3f3f;

struct Edge
{
  int s, d, w;
  Edge* next;
}edge[MAX_M];

int cnt = -1;
Edge* adj[MAX_N];

inline void init_p(Edge* p) {
  p = &edge[++cnt];
  p->next = NULL;
}

inline int read() {
  int x = 0, sign = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (!isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return x * sign;
}

int main() {
  int n = read();
  int m = read();
  // scanf("%d%d", &n, &m);
  memset(adj, 0, sizeof(adj));
  _rep(i, 0, m) {
    Edge* p;
    init_p(p);
    scanf("%d%d%d", &(p->s), &(p->d), p->w);
    p->next = adj[p->s];
    adj[p->s] = p;
  }
}
