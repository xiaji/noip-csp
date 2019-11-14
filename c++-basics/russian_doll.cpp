#include <bits/stdc++.h>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

class Solution {
  // reference for # and struct and class
  // pointer for treenode and array
  bool cmp(const pair<int, int>& x, const pair<int, int>& y) {
    return x.first == y.first ? x.second > y.second : x.first < y.first;
  }

public:
    /*
     * @param envelopes: a number of envelopes with widths and heights
     * @return: the maximum number of envelopes
     */
  int maxEnvelopes(vector<pair<int, int> >& envelopes) {
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), cmp);
    int b[n + 1];
    b[0] = - INT_MAX - 1;
    int top = 0;
    _rep(i, 0, n) {
      int j = lower_bound(b, b + top + 1, envelopes[i].second) - b;
      b[j] = envelopes[i].second;
      if (j > top) top = j;
    }
    return top;
  }
};