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

void print_vec(vector<int> arr) {
  for (int val : arr) {
    cout << val << ' ';
  }
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
  /*
  for (int val : data) {
    cout << val << ' ';
  }*/
  return 0;
}
