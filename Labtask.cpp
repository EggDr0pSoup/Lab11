#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Library
{
private:
    std::vector<std::string> books;

public:
    // constructor
    // creates a library with no books
    Library() {}

    // Adds the given book to the library and returns true
    // returns false if the book already exists or if the library
    //   already has 10 books
    bool addBook(std::string bookName)
    {
        if (books.size() < 10 && std::find(books.begin(), books.end(), bookName) == books.end())
        {
            books.push_back(bookName);
            return true;
        }
        return false;
    }

    // Removes the given book name from the library by setting the
    //   corresponding string to "", and returns true
    // returns false if the library does not have the given book
    bool removeBook(std::string bookName)
    {
        auto it = std::find(books.begin(), books.end(), bookName);
        if (it != books.end())
        {
            books.erase(it);
            return true;
        }
        return false;
    }
    void print()
    {
        for (const auto &book : books)
        {
            std::cout << book << std::endl;
        }
    }
};

void Library::print()
{
    cout << "Library contents: " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (books[i] != "")
            cout << books[i] << endl;
    }
}

int main()
{
    Library library;

    // ask for commands and execute
    char command = 's';
    string bookName;
    while (command != 'q')
    {
        cout << "Enter command: ";
        cin >> command;
        if (command == 'p')
        {
            library.print();
        }
        if (command == 'a')
        {
            cin >> bookName;
            bool check = library.addBook(bookName);
        }
        if (command == 'r')
        {
            cin >> bookName;
            bool check = library.removeBook(bookName);
        }
    }
    cout << "Exiting" << endl;
    return 0;
}