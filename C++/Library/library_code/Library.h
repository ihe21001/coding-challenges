#pragma once // Ensures this header is only included once during compilation.

#include "Book.h" // Include the Book class.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Library {
private:
    vector<Book> books; // Private vector to store a collection of Book objects.

public:
    // Constructor: Initializes a new Library object.
    Library();
    
    void addBook(const Book& book);

    void removeBook(const string& isbn);

    void listBooks();
    
    };
