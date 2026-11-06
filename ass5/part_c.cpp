#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    int copies;

public:
    Book(int bookId = 0, string bookTitle = "", string bookAuthor = "", int bookCopies = 0)
        : id(bookId), title(bookTitle), author(bookAuthor), copies(bookCopies) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getCopies() const { return copies; }

    void displayBookInfo() const
    {
        cout << "Book Id: " << id << "\n";
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Copies: " << copies << "\n";
    }
};

int inputBookId()
{
    int id;
    cout << "Enter the book id: ";
    cin >> id;
    return id;
}

class Library
{
    Book books[50];
    int n;

public:
    Library() : n(0) {}

    bool isEmpty() const { return n == 0; }

    void Show(int mid) const { books[mid].displayBookInfo(); }

    void AddBook()
    {
        if (n == 50)
        {
            cout << "Record is Full\n";
            return;
        }

        int id, copies;
        string title, author;

        cout << "Enter book id: ";
        cin >> id;
        cin.ignore();
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter copies: ";
        cin >> copies;

        Book b(id, title, author, copies);

        int i = n - 1;
        while (i >= 0 && books[i].getId() > b.getId())
        {
            books[i + 1] = books[i];
            i--;
        }
        books[i + 1] = b;
        n++;
        cout << "Book Added\n";
    }

    void Display() const
    {
        if (isEmpty())
        {
            cout << "No Books in Library\n";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "Book " << i + 1 << "\n";
            Show(i);
        }
    }

    void SearchById(int id) const
    {
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (books[mid].getId() == id)
            {
                cout << "Book Found!!\n";
                Show(mid);
                return;
            }
            else if (books[mid].getId() < id)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << "Book with id " << id << " is not available\n";
    }
};

int main()
{
    int ch = 1;
    Library lib;
    while (ch != 0)
    {
        int choice;
        cout << "Enter 1 to add a book\n";
        cout << "Enter 2 to display all books\n";
        cout << "Enter 3 to search a book by id\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lib.AddBook();
            break;
        case 2:
            lib.Display();
            break;
        case 3:
            lib.SearchById(inputBookId());
            break;
        default:
            cout << "Wrong Choice!\n";
            break;
        }
        cout << "Do you want to Continue 1 or 0\n";
        cin >> ch;
    }
    return 0;
}
