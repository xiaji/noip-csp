#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;


bool diff(vi& v){
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] == v[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int i;
  vi v;
  while (cin >> i) {
    v.push_back(i);
  }
  sort(v, v + v.size());
  cout << diff(v);
  return 0;
}