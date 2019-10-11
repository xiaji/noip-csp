#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
  /* wchar_t a = '\u0041';
  char32_t mug = U'\U0001F37A';
  printf("a is right ? %c.", a);
  printf("mug is %lc.", mug);*/
  char question[] = "Please enter your name: ";
  char greet[] = "Hello, ";
  char name[90];
  cout << question;
  cin >> name;
  cout << greet << name << endl;
  string mystring;
  getline(cin, mystring);
  cout << mystring;
  return 0;
}
