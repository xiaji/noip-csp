#include <bits/stdc++.h>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

namespace io_f
{
void open_f()
{
  freopen("match.in", "r", stdin);
  freopen("match.out", "w", stdout);
}

void close_f()
{
  fclose(stdin);
  fclose(stdout);
}

int read()
{
  int x = 0, sign = 1;
  char ch = 0;
  while (!isdigit(ch))
  {
    if (ch == '-')
      sign = -1;
    ch = getchar();
  }
  while (isdigit(ch))
  {
    x = (x << 3) + (x << 1) + (ch - '0');
    ch = getchar();
  }
  return x * sign;
}

void init()
{
  n = read();
  _rep(i, 0, n)
  {
    a[i].v = read();
    a[i].id = i;
  }
  _rep(i, 0, n)
  {
    b[i].v = read();
    b[i].id = i;
  }
}
} // namespace io_f
using namespace std;
typedef long long ll;
const int MOD = 99999997;
const int MAXN = 100005;
int n, temp[MAXN], c[MAXN];
ll ans = 0;

struct node
{
  int id, v;
} a[MAXN], b[MAXN];

bool cmp(node &x, node &y)
{
  return x.v < y.v;
}

void merge_sort(int start, int end)
{
  if (start >= end)
    return;
  int mid = start + (end - start) / 2;
  merge_sort(start, mid);
  merge_sort(end, mid);
  int i = start, j = mid + 1;
  for (int k = start; k <= end; ++k)
  {
    temp[k] = c[k];
  }
  for (int k = start; k <= end; ++k)
  {
    if (i > mid)
      c[k] = temp[j++];
    else if (j > end)
      c[k] = temp[i++];
    else if (temp[i] <= temp[j])
      c[k] = temp[i++];
    else
    {
      c[k] = temp[j++];
      ans = (ans + mid - i + 1) % MOD;
    }
  }
}

int main()
{
  io_f :: open_f();
  io_f :: init();
  sort(a, a + n, cmp);
  sort(b, b + n, cmp);
  _rep(i, 0, n) c[a[i].id] = b[i].id;
  merge_sort(0, n - 1);
  printf("%lld", ans);
  return 0;
}
