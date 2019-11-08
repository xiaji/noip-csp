#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define _rep(i, a, b) for(int i = (a); i < (b); ++i)
#define _dwn(i, a, b) for(int i = (a); i >= (b); --i)

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
  int lowbit(int x) {
    // ((~(x)) + 1) & x
    // return x & (-x);
    return ((~(x)) + 1) & x;
  }

  void add(int x) {
    while (x <= n) {
      bits[x]++;
      x += lowbit(x);      
    }
  }

  int sum(int i) {
    int res = 0;
    while (i > 0) {
      res += bits[i];
      i -= lowbit(i);
    }
    return res;
  }

  int get_sum(int i) {
    return sum(n - 1) - sum(i);
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
  _rep(i, 1, n + 1) {
    a[i].val = read();
    a[i].id = i;
  }
  _rep(i, 1, n + 1) {
    b[i].val = read();
    b[i].id = i;
  }
}
/**
 * 出现的错误
 * 1. sum():for(int i = x; i > 0; i -= lowbit(i))
 * 不能为 i >= 0, 会有死循环产生，因为 0 - 0 == 0
 * 所以用bitree的时候，记住bits数组的下标一定是从 1 开始；这就是和merge sort的区别
 * 2. add(): for(int i = x; i <= n; i += lowbit(i)) 对应的要进行相应的修改
 * 因为我们bits的下标范围是从[1, n]
 * 3. 统计 ans 的时候，从最后一位往前开始插入，统计现在这个时候，比 c[i] 小的数都有几个
 * 因为是从后往前开始加，那个数即为逆序对的个数。计算c[i], not c[i] - 1
 * 因为题目已知，没有重复的数值。之后c[i]还没入队，所以没有相等的数目会影响结果
 * 
 * */
int main() {
  open();
  init();
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  _rep(i, 1, n + 1) {
    c[a[i].id] = b[i].id;
    bits[i] = 0;
  }
  ll ans = 0;
  //bits[0] = 0;  
  _dwn(i, n, 1) {
    ans = (ans + sum(c[i])) % MOD;
    add(c[i]);
  }
  printf("%lld", ans);
  close();
  return 0;
}
