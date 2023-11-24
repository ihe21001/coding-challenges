#include <iostream>
#include <string>
#include <limits> 
#include "Library.h"
#include "Book.h"

using namespace std; 

int main(){
    Library myLibrary;
    string title, author, isbn;
    int choice;

    cout << "start" << endl;
    while (true)
    {
        cout << endl << "Library Management System" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. List book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the book title: ";
            getline(cin, title);

            cout << "Enter the author of the book: ";
            getline(cin, author);

            cout << "Enter the books isbn code: ";
            cin >> isbn;

            myLibrary.addBook(Book(title,author,isbn));
            break;
        case 2:
            cout << "Enter ISBN of book to remove: ";
            cin >> isbn;
            myLibrary.removeBook(isbn);
            break;
        case 3:
            myLibrary.listBooks();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice";
        }
    }
    
    return 0;
}
