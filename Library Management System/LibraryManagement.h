#ifndef LIBRARYMANAGEMENT_H_INCLUDED
#define LIBRARYMANAGEMENT_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Book class definition
class Book {
private:
    string title;
    string author;
    string ISBN;
    string pubDate;
    bool isAvailable;

public:
    Book(string t, string a, string i, string pd);

    string getTitle();
    string getAuthor();
    string getISBN();
    string getPubDate();
    bool getStatus();

    void setTitle(string t);
    void setAuthor(string a);
    void setISBN(string i);
    void setPubDate(string pd);
    void setStatus(bool status);

    void displayBook();
};

// Member class definition
class Member {
private:
    string name;
    int memberId;
    string contactInfo;
    vector<Book*> borrowedBooks;

public:
    Member(string n, int id, string contact);

    string getName();
    int getId();
    string getContact();

    void setName(string n);
    void setContact(string contact);

    void borrowBook(Book* book);
    void returnBook(Book* book);
    void displayBorrowedBooks();
};

// Library class definition
class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook();
    void removeBook();
    void registerMember();
    void borrowBook();
    void returnBook();
    void displayAllBooks();
    void displayAllMembers();
};


#endif // LIBRARYMANAGEMENT_H_INCLUDED
