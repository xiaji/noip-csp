#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  string str;
  cout << "Please enter your name: ";
  getline(cin, str);
  cout << "name is : " << str << endl;
  float price = 0.0f;
  int quantity = 0;
  cout << "Please enter price : ";
  getline(cin, str);
  stringstream(str) >> price;
  cout << "Please enter quantity: ";
  getline(cin, str);
  stringstream(str) >> quantity;
  cout << "Total price: " << price * quantity << endl;
  return 0;
}
