#include <iostream>
using namespace std;

void times_ref(int& a, int& b) {
  a *= 2;
  b *= 2;
}

void times(int a, int b) {
  a *= 2;
  b *= 2;
}

void prevnext(int x, int& prev, int& next) {
  prev = x * 2;
  next = prev + 1;
}

int main() {
  int a = 2, b = 3;
  times(a, b);
  cout << "call times method without ampersand sign (&): ";
  cout << "a: " << a << " b: " << b << endl;
  times_ref(a, b);
  cout << "call times method with ampersand sign: ";
  cout << "a: " << a << " b: "<< b << endl;
  prevnext(0, a, b);
  cout << "call prevnext(int x, int& prev, int& next): ";
  cout << "a: " << a << " b: "<< b << endl;
  int& temp = a;
  int x = temp;
  temp = 10;
  cout << "x: " << x << " temp: " << temp << " a: " << a << endl;
  cout << "x: " << &x << endl;
  cout << "temp: " << &temp << endl;
  cout << "a: " << &a << endl;
  return 0;
}
