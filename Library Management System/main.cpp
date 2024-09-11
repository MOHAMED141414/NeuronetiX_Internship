#include<iostream>
#include"LibraryManagement.h"

int main() {
    Library myLibrary;
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Register Member\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Display All Members\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            myLibrary.addBook();
            break;
        case 2:
            myLibrary.removeBook();
            break;
        case 3:
            myLibrary.registerMember();
            break;
        case 4:
            myLibrary.borrowBook();
            break;
        case 5:
            myLibrary.returnBook();
            break;
        case 6:
            myLibrary.displayAllBooks();
            break;
        case 7:
            myLibrary.displayAllMembers();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
