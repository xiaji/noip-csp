#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

struct Person {
  int age;
  string name;
};

bool sort_age(const Person &p1, const Person &p2) {
  return p1.age < p2.age;
}

bool sort_name(const Person &p1, const Person &p2) {
  return p1.name < p2.name;
}

int main() {
  vi test1(5);
  for (int i = 0; i < 5; i++) {
    cout << "Please input the " << i + 1 << " vector " << endl;
    cin >> test1[i];
  }
  sort(test1.begin(), test1.end());
  cout << "after sorting: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << test1[i] << " ";
  }
  cout << "\n";
  vector<Person> persons(5);
  for (int i = 0; i < 5; i++) {
    cout << "Please input the " << i + 1 << " Person's age:" << endl;
    cin >> persons[i].age;
    cout << "Please input the " << i + 1 << " Person's name:" << endl;
    cin >> persons[i].name;
  }
  sort(persons.begin(), persons.end(), sort_age);
  cout << "after sorting by age: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << persons[i].age << " ";
  }
  cout << "\n";
  sort(persons.begin(), persons.end(), sort_name);
  cout << "after sorting by name: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << persons[i].name << " ";
  }
  cout << "\n";
  return 0;
}