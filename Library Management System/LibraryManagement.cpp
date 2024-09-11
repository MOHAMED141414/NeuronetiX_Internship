#include"LibraryManagement.h"

// Book class implementations
Book::Book(string t, string a, string i, string pd)
    : title(t), author(a), ISBN(i), pubDate(pd), isAvailable(true) {}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getISBN() { return ISBN; }
string Book::getPubDate() { return pubDate; }
bool Book::getStatus() { return isAvailable; }

void Book::setTitle(string t) { title = t; }
void Book::setAuthor(string a) { author = a; }
void Book::setISBN(string i) { ISBN = i; }
void Book::setPubDate(string pd) { pubDate = pd; }
void Book::setStatus(bool status) { isAvailable = status; }

void Book::displayBook() {
    cout << "Title: " << title << "\nAuthor: " << author
         << "\nISBN: " << ISBN << "\nPublication Date: " << pubDate
         << "\nStatus: " << (isAvailable ? "Available" : "Checked Out") << endl;
}

// Member class implementations
Member::Member(string n, int id, string contact)
    : name(n), memberId(id), contactInfo(contact) {}

string Member::getName() { return name; }
int Member::getId() { return memberId; }
string Member::getContact() { return contactInfo; }

void Member::setName(string n) { name = n; }
void Member::setContact(string contact) { contactInfo = contact; }

void Member::borrowBook(Book* book) {
    if (book->getStatus()) {
        borrowedBooks.push_back(book);
        book->setStatus(false);
        cout << "Book borrowed successfully.\n";
    } else {
        cout << "Book is already checked out.\n";
    }
}

void Member::returnBook(Book* book) {
    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        book->setStatus(true);
        cout << "Book returned successfully.\n";
    } else {
        cout << "Book not found in borrowed list.\n";
    }
}

void Member::displayBorrowedBooks() {
    cout << "Borrowed books for " << name << ":\n";
    for (auto& book : borrowedBooks) {
        book->displayBook();
    }
}

// Library class implementations
void Library::addBook() {
    string title, author, ISBN, pubDate;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);
    cout << "Enter publication date: ";
    getline(cin, pubDate);

    books.push_back(Book(title, author, ISBN, pubDate));
    cout << "Book added successfully.\n";
}

void Library::removeBook() {
    string isbn;
    cout << "Enter ISBN of the book to remove: ";
    cin >> isbn;
    auto it = find_if(books.begin(), books.end(),
        [&](Book& b) { return b.getISBN() == isbn; });

    if (it != books.end()) {
        books.erase(it);
        cout << "Book removed successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

void Library::registerMember() {
    string name, contact;
    int id;
    cout << "Enter member name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter member ID: ";
    cin >> id;
    cout << "Enter contact info: ";
    cin.ignore();
    getline(cin, contact);

    members.push_back(Member(name, id, contact));
    cout << "Member registered successfully.\n";
}

void Library::borrowBook() {
    int memberId;
    string isbn;
    cout << "Enter member ID: ";
    cin >> memberId;
    cout << "Enter ISBN of the book: ";
    cin >> isbn;

    auto memIt = find_if(members.begin(), members.end(),
        [&](Member& m) { return m.getId() == memberId; });
    auto bookIt = find_if(books.begin(), books.end(),
        [&](Book& b) { return b.getISBN() == isbn; });

    if (memIt != members.end() && bookIt != books.end()) {
        memIt->borrowBook(&(*bookIt));
    } else {
        cout << "Member or book not found.\n";
    }
}

void Library::returnBook() {
    int memberId;
    string isbn;
    cout << "Enter member ID: ";
    cin >> memberId;
    cout << "Enter ISBN of the book: ";
    cin >> isbn;

    auto memIt = find_if(members.begin(), members.end(),
        [&](Member& m) { return m.getId() == memberId; });
    auto bookIt = find_if(books.begin(), books.end(),
        [&](Book& b) { return b.getISBN() == isbn; });

    if (memIt != members.end() && bookIt != books.end()) {
        memIt->returnBook(&(*bookIt));
    } else {
        cout << "Member or book not found.\n";
    }
}

void Library::displayAllBooks() {
    cout << "Books in Library:\n";
    for (auto& book : books) {
        book.displayBook();
        cout << "-----------------------\n";
    }
}

void Library::displayAllMembers() {
    cout << "Library Members:\n";
    for (auto& member : members) {
        cout << "Name: " << member.getName() << "\nID: " << member.getId()
             << "\nContact: " << member.getContact() << endl;
        cout << "-----------------------\n";
    }
}
