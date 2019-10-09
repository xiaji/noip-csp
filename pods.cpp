#include <cstdio>

struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};

int main() {
  Book book;
  book.pages = 456;
  printf("the book has %d pages.", book.pages);
  return 0;
}
