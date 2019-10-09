#include <cstdio>

struct ClockOfTheLongNow {
  ClockOfTheLongNow(int year_in) {
    if (!set_year(year_in)) {
      year = 2019;
    }
  }
  bool set_year(int new_year) {
    if (new_year < 2019) return false;
    year = new_year;
    return true;
  }
  int get_year() {
    return year;
  }
  private:
  int year;
  void add_year() {
    year++;
  }
};

int main() {
  ClockOfTheLongNow clock{ 2020 };
  /*if (!clock.set_year(2017)) {
    clock.set_year(2020);
  }
  clock.add_year();*/
  printf("The year is %d\n", clock.get_year());
}

