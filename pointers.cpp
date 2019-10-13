#include <iostream>
using namespace std;

int count(int* p, int x) {
  if (p == nullptr) return 0;
  int res = 0;
  for (; *p != 8; ++p) {
    cout << p << endl;
    if (*p == x) {
      res++;
    }
  }
  return res;
}

void fp(char* p) {
  while (*p) {
    cout << ++*p << ' ';
    p++;
  }
}

int main() {
  int v[] = {1, 3, 5, 6, 7, 8};
  cout << count(v, 5) << endl;
  for (auto& x : v) 
    cout << x++ << endl;
    // cout << x << endl;
  // cout << count(v, 4) << endl;
  for (auto x : v) 
    cout << x << endl;
  cout << count(v, 5) << endl;
  int a[2][2] = {{1,2},{3,4}};
  cout << &a << endl;
  cout << &a[0] << endl;
  cout << &a[0][0] << endl;
  char str[] = "detsfew";
  fp(str);
  cout << str << endl;
  return 0;
}
    
