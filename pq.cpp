//#include <priority_queue>
#include <queue>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
inline void print_queue(T& q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

inline bool cmp (int x, int y) {
  return (x ^ 1) > (y ^ 1);
}

int main() {
  priority_queue<int> q;
  q.push(3);
  q.push(34);
  q.push(30);
  q.push(4);
  q.push(23);
  q.push(234);
  print_queue(q);
  priority_queue<int, vector<int>, greater<int> > q2;
  q2.push(3);
  q2.push(34);
  q2.push(30);
  q2.push(4);
  q2.push(23);
  q2.push(234);
  print_queue(q2);
  return 0;
}
