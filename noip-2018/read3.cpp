#include <cstdio>
#include <iostream> 
using namespace std; 
const int N = 110; 
bool isUse[N];
int n, t;
int a[N], b[N];
bool isSmall() {
  for (int i = 1; i <= n; ++i)
    if (a[i] != b[i]) return a[i] < b[i];
  return false;
}

void print_arr(int* a) {
  int* start = ++a;
  int* end = start;
  while (end - start < n) {
    cout << *end << ' ';
    end++;
  }
  cout << endl;
}

void print_arr(bool* a) {
  bool* start = ++a;
  bool* end = start;
  while (end - start < n) {
    cout << *end << ' ';
    end++;
  }
  cout << endl;
}
   
bool getPermutation(int pos) {
  if (pos > n) {
    return isSmall();
  }
  /*cout << "begin recursion : " << endl;
  cout << "pos : " << pos << endl;
  cout << "use : ";
  print_arr(isUse);
  cout << "b : ";
  print_arr(b);*/
  for (int i = 1; i <= n; ++i) {
    if (!isUse[i]) {
      b[pos] = i; isUse[i] = true;
      if (getPermutation(pos + 1)) {
        return true;
      }
      isUse[i] = false;
    }
  }
  /*cout << "recursion end : " << endl;
  cout << "pos : " << pos << endl;
  cout << "use : ";
  print_arr(isUse);
  cout << "b : ";
  print_arr(b);*/
  return false;
}

void getNext() {
  for (int i = 1; i <= n; ++i) {
    isUse[i] = false;
  }
  getPermutation(1);
  for (int i = 1; i <= n; ++i) {
    a[i] = b[i]; 
  }
}

int main() {
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  
  for (int i = 1; i <= t; ++i) {
    getNext();
    // print_arr(isUse);
    print_arr(a);
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d", a[i]);
    if (i == n) putchar('\n'); 
    else putchar(' ');
  }
  return 0; 
}