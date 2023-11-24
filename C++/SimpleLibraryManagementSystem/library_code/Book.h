#pragma once // Ensures this header is only included once during compilation.
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title; 
    string author; 
    string isbn; 

public:
    // Constructor: Initializes a new Book object with given title, author, and isbn.
    Book(string title, string author, string isbn);
    
    // Getter: title of the book.
    string getTitle() const;

    // Getter: author of the book.
    string getAuthor() const;

    // Getter: ISBN of the book.
    string getISBN() const;
    
};
