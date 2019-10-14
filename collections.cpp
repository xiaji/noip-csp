#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void desc_sort(vector<int>& arr) {
  sort(arr.begin(), arr.end(), greater<int>());
}

void asc_sort(vector<int>* arr) {
  sort(arr->begin(), arr->end());
}

void print_vec(vector<int>& arr) {
  for (int val : arr) {
    cout << val << ' ';
  }
  cout << '\n';
}

void remove_even(vector<int>& arr) {
  for (auto i = arr.begin(); i < arr.end(); i++) {
    cout << "element: " << *i << " address: " << &(*i) << endl;
    if (*i % 2 == 0) {
      arr.erase(i);
      // erase at address i element, we should move the pointer to the prev position
      i--;
    }
  }
  //cout << '\n';
}

int main() {
  vector<int> data = {132, 22, 3};
  data.push_back(12);
  // cout << data[3] << endl;
  desc_sort(data);
  print_vec(data);
  cout << endl;
  data.push_back(243);
  data.push_back(3);
  asc_sort(&data);
  print_vec(data);
  int first_elem = data.front() + 1;
  data.front() += 1;
  cout << data.front() << endl;
  remove_even(data);
  print_vec(data);
  vector<int>::iterator it1, it2;
  it1 = data.begin();
  it2 = data.end();
  it2--;
  cout << "iterator pointer: " << *it2 << endl;
  cout << "last element address" << &data[data.size() - 1] << endl;
  it2--;
  cout << "iterator pointer: " << *it2 << endl;
  cout << "last element address " << &data[data.size() - 2] << endl;
  data.erase(it1, it2);
  for (auto i = data.begin(); i != data.end(); i++) {
    cout << *i << ' ';
  }
  cout << endl;
  /*
  for (int val : data) {
    cout << val << ' ';
  }*/
  return 0;
}
