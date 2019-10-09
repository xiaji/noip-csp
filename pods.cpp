#include <cstdio>

struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};

struct ClockOfTheLongNow {
  int year;
  void add_year() {
    year++;
  }
};

int main() {
  Book book;
  book.pages = 456;
  printf("the book has %d pages.", book.pages);
  ClockOfTheLongNow clock;
  clock.year = 2017;
  clock.add_year();
  printf("year: %d\n", clock.year);
  clock.add_year();
  printf("year: %d\n", clock.year);
  return 0;
}
