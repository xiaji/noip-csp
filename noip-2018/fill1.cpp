#include <iostream>
using namespace std;
const int N = 100010;
int n;
int L[N], R[N], a[N];
void print_arr(int *p, int size)
{
  p++;
  for (int i = 0; i < size; i++)
  {
    cout << *p << ' ';
    p++;
  }
  cout << endl;
}
int main()
{
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    int x;
    cin >> x;
    a[x] = i;
  }

  for (int i = 1; i <= n; ++i)
  {
    L[i] = i - 1;
    R[i] = i + 1;
  }

  for (int i = 1; i <= n; ++i)
  {
    cout << "L[a[i]]: " << L[a[i]] << endl;
    cout << "R[a[i]]: " << R[a[i]] << endl;
    L[R[a[i]]] = L[a[i]];
    R[L[a[i]]] = R[a[i]];
    cout << "L : ";
    print_arr(L, n);
    cout << "R : ";
    print_arr(R, n);
  }
  // print_arr(R, n);
}