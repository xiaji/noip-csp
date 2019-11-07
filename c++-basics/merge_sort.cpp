#include <iostream>
#include <vector> 
#include <algorithm>
#define _rep(i, a, b) for(int i = (a); i < (b); ++i)

using namespace std;
typedef vector<int> vi;
int cnt = 0;

void merge_array(int* nums, int start, int mid, int end, int* temp) {
  int i = start, j = mid + 1;
  _rep(n, start, end + 1) temp[n] = nums[n];
  for (int k = start; k <= end; ++k) {
    if (i > mid) nums[k] = temp[j++];
    else if (j > end) nums[k] = temp[i++];
    else if (temp[i] <= temp[j]) nums[k] = temp[i++];
    else {
      nums[k] = temp[j++];
      cnt += mid - i + 1;
    }
  }
}

void merge_sort(int* nums, int start, int end, int* temp) {
  if (start >= end) {
    return;
  }
  int mid = start + (end - start) / 2;
  merge_sort(nums, start, mid, temp);
  merge_sort(nums, mid + 1, end, temp);
  merge_array(nums, start, mid, end, temp);
}

int main() {
  vi v;
  int i;
  while (cin >> i) {
    v.push_back(i);
  }
  int size = v.size();
  int nums[size], temp[size];
  //memcpy(nums, &v, v.size());
  _rep(i, 0, size) {
    nums[i] = v[i];
    //cout << nums[i] << " ";
  }
  sort(v.begin(), v.end());
  _rep(i, 0, size) {
    printf("%d ", v[i]);
  }
  printf("\n");
  merge_sort(nums, 0, size - 1, temp);
  _rep(i, 0, size) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  printf("%d", cnt);
  return 0;
}
