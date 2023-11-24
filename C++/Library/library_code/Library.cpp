#include <iostream>
#include <string>
using namespace std;

#include "Library.h" // Include the definition of the Library class.

Library::Library() {
}

// Add a book to the library
void Library::addBook(const Book& book) {
    cout << "Add Book" << book.getTitle() << endl;
    books.push_back(book);
}

// Removes a Book from the library by its ISBN.
void Library::removeBook(const string& isbn) {
    bool found = false;
    for (auto b = books.begin(); b != books.end(); ) {
        if (b->getISBN() == isbn) {
            books.erase(b);
            found = true;
            cout << "Book with ISBN " << isbn << " removed." << endl;
            return;
        } else {
            b++;
        }
    }
    if (found == false){
        cout << " Wrong ISBN. " << endl;
    }
}

// Lists all the Books currently in the library.
void Library::listBooks() {
    cout << "Listing all books:" << endl;
    
    if (books.empty()) {
        cout << "..The library is empty.." << endl;
        return;
    }

    for (const auto& book : books) {
        cout << "Title: " << book.getTitle() << "  Author: " << book.getAuthor() << "  ISBN: " << book.getISBN() << endl;
    }
}
