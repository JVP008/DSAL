#include <iostream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;
    string city;
    Contact *next;

    Contact(string n, string p, string e, string c) {
        name = n;
        phone = p;
        email = e;
        city = c;
        next = NULL;
    }

    void show() {
        cout << name << " " << phone << " " << email << " " << city << endl;
    }
};

class ContactList {
    Contact *head;

    Contact* find(string name) {
        Contact *temp = head;
        while (temp != NULL) {
            if (temp->name == name)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

public:
    ContactList() {
        head = NULL;
    }

    void add(string n, string p, string e, string c) {
        Contact *node = new Contact(n, p, e, c);
        if (head == NULL) {
            head = node;
        } else {
            Contact *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = node;
        }
        cout << "Contact saved" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "No contacts to show" << endl;
            return;
        }
        cout << "\nName | Phone | Email | City" << endl;
        Contact *temp = head;
        while (temp != NULL) {
            temp->show();
            temp = temp->next;
        }
    }

    void search(string name) {
        Contact *c = find(name);
        if (c == NULL)
            cout << "No contact found with that name" << endl;
        else {
            cout << "Contact found:" << endl;
            c->show();
        }
    }

    void update(string name) {
        Contact *c = find(name);
        if (c == NULL) {
            cout << "No contact found with that name" << endl;
            return;
        }
        string p, e, ct;
        cout << "Enter new phone: ";
        getline(cin, p);
        cout << "Enter new email: ";
        getline(cin, e);
        cout << "Enter new city: ";
        getline(cin, ct);

        if (p != "") c->phone = p;
        if (e != "") c->email = e;
        if (ct != "") c->city = ct;
        cout << "Contact updated" << endl;
    }

    void remove(string name) {
        if (head == NULL) {
            cout << "Contact list is empty" << endl;
            return;
        }
        if (head->name == name) {
            Contact *t = head;
            head = head->next;
            delete t;
            cout << "Contact deleted" << endl;
            return;
        }
        Contact *temp = head;
        while (temp->next != NULL && temp->next->name != name)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "No contact found with that name" << endl;
        } else {
            Contact *t = temp->next;
            temp->next = t->next;
            delete t;
            cout << "Contact deleted" << endl;
        }
    }

    int count() {
        int c = 0;
        Contact *temp = head;
        while (temp != NULL) {
            c++;
            temp = temp->next;
        }
        return c;
    }
};

int main() {
    ContactList book;
    int ch;
    string name, phone, email, city;

    while (true) {
        cout << "\n1.Add contact";
        cout << "\n2.Display all contacts";
        cout << "\n3.Search contact";
        cout << "\n4.Update contact";
        cout << "\n5.Delete contact";
        cout << "\n6.Total contacts";
        cout << "\n7.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        cin.ignore();

        if (ch == 1) {
            cout << "Name: ";
            getline(cin, name); //space can cause the problem!
            cout << "Phone: ";
            getline(cin, phone);
            cout << "Email: ";
            getline(cin, email);
            cout << "City: ";
            getline(cin, city);
            book.add(name, phone, email, city);
        } else if (ch == 2) {
            book.display();
        } else if (ch == 3) {
            cout << "Enter name to search: ";
            getline(cin, name);
            book.search(name);
        } else if (ch == 4) {
            cout << "Enter name to update: ";
            getline(cin, name);
            book.update(name);
        } else if (ch == 5) {
            cout << "Enter name to delete: ";
            getline(cin, name);
            book.remove(name);
        } else if (ch == 6) {
            cout << "Total contacts: " << book.count() << endl;
        } else if (ch == 7) {
            cout << "Bye" << endl;
            break;
        } else {
            cout << "Wrong choice, try again" << endl;
        }
    }
    return 0;
}
