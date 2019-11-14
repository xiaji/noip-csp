#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

class Solution {
  public:
    void hash_arr(int* b, int size) {
      sort(b, b + size);
      int len = std :: unique(b, b + size) - b;
      //vector<int> res(len);
      _rep(i, 0, size) {
        b[i] = lower_bound(b, b + len, b[i]) - b;
      }
    }
};
