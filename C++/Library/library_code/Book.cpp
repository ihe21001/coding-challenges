#include <iostream>
#include <string>
using namespace std;

#include "Book.h" 

Book::Book(string t, string a, string i)
    : title(t), author(a), isbn(i) {}

string Book::getTitle() const{
    return title;
}

string Book::getAuthor() const{
    return author;
}

string Book::getISBN() const{
    return isbn;
}
