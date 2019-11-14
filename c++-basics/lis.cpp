#include <bits/stdc++.h>
#define _rep(i, a, b) for (int i = (a); i < (b); ++i)

const int INT_MIN = 0x80000000;

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
      int n = nums.size();
      //int dp[n];
      int b[n + 1];
      b[0] = INT_MIN;
      int top = 0;
      _rep(i, 0, n) {
        // vector or array
        // lower_bound: find the first position >= val
        // upper_bound: find teh first pos > val
        // mistake1: j + 1 change to j
        // mistake2: b + top to b + top + 1
        // top is the index of b, so lower or upper is [a, a + size)
        // int j = lower_bound(b, b + top, nums[i]) - b;
        // b[j + 1] = nums[i];
        // if (j + 1 > top) top = j + 1;
        int j = lower_bound(b, b + top + 1, nums[i]) - b;
        b[j] = nums[i];
        if (j > top) top = j;
      }
      return top; 
    }
};