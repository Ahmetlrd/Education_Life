#include "book.h"
#include <iostream>

Book::Book(const string& title, const string& author, int year, int pages) :
    title(title), author(author), year(year), pages(pages) {}

string Book::getTitle() const {
  return title;
}

string Book::getAuthor() const {
  return author;
}

int Book::getYear() const {
  return year;
}

int Book::getPages() const {
  return pages;
}

void Book::printInfo() const {
    cout << "Title: " << getTitle() << std::endl;
    cout << "Author: " << getAuthor() << std::endl;
    cout << "Year: " << getYear() << std::endl;
    cout << "Pages: " << getPages() << std::endl;
}
