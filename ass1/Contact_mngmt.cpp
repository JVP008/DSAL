#include <bits/stdc++.h>
using namespace std;

class Cnode
{
private:
    string name;
    string phone;
    string email;
    string city;
    Cnode *next;

public:
    Cnode() : next(NULL) {}
    friend class ContactList;
    friend Cnode *getNode(string, string, string, string);
};

// Free function - declared as friend above
Cnode *getNode(string name, string phone, string email, string city)
{
    Cnode *newnode = new Cnode();
    newnode->name = name;
    newnode->phone = phone;
    newnode->email = email;
    newnode->city = city;
    return newnode;
}

string getName()
{
    string name;
    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, name);
    return name;
}

class ContactList : public Cnode
{
private:
    Cnode *head;

public:
    ContactList() : head(NULL) {}

    bool isEmpty()
    {
        return head == NULL;
    }

    // Add a new contact at the end
    void AddContact()
    { 
        string name, phone, email, city;
        cin.ignore();

        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter phone: ";
        getline(cin, phone);
        cout << "Enter email: ";
        getline(cin, email);
        cout << "Enter city: ";
        getline(cin, city);

        Cnode *newnode = getNode(name, phone, email, city);

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            Cnode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        cout << "Contact Saved\n";
    }

    // Display all contacts
    void Display()
    {
        if (isEmpty())
        {
            cout << "No Contacts to Show\n";
            return;
        }

        Cnode *temp = head;
        cout << "Name | Phone | Email | City\n";

        while (temp != NULL)
        {
            // Direct access to private fields thanks to friend class
            cout << temp->name << " | "
                 << temp->phone << " | "
                 << temp->email << " | "
                 << temp->city << "\n";
            temp = temp->next;
        }
    }

    // Search a contact by name
    void Search(string name)
    {
        Cnode *temp = head;

        while (temp != NULL && temp->name != name)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Contact Not in List\n";
        }
        else
        {
            cout << "Contact Found!!\n";
            cout << temp->name << " | "
                 << temp->phone << " | "
                 << temp->email << " | "
                 << temp->city << "\n";
        }
    }

    // Update an existing contact
    void Update(string name)
    {
        Cnode *temp = head;

        while (temp != NULL && temp->name != name)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Contact not found\n";
            return;
        }

        cout << "Enter new phone: ";
        getline(cin, temp->phone);
        cout << "Enter new email: ";
        getline(cin, temp->email);
        cout << "Enter new city: ";
        getline(cin, temp->city);

        cout << "Contact Updated\n";
    }

    // Delete a contact by name
    void Delete(string name)
    {
        if (isEmpty())
        {
            cout << "Cant Delete\n";
            return;
        }

        if (head->name == name)
        {
            Cnode *temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted Successfully\n";
            return;
        }

        Cnode *temp = head;

        while (temp->next != NULL && temp->next->name != name)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Contact not found\n";
            return;
        }

        Cnode *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        cout << "Deleted Successfully\n";
    }

    // Count total contacts
    void Count()
    {
        int c = 0;
        Cnode *temp = head;

        while (temp != NULL)
        {
            c++;
            temp = temp->next;
        }

        cout << "Total Contacts: " << c << "\n";
    }
};

int main()
{
    int ch = 1;
    ContactList list;

    while (ch != 0)
    {
        int choice;

        cout << "Enter 1 to add a contact\n";
        cout << "Enter 2 to display all contacts\n";
        cout << "Enter 3 to search a contact\n";
        cout << "Enter 4 to update a contact\n";
        cout << "Enter 5 to delete a contact\n";
        cout << "Enter 6 to count contacts\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.AddContact();
            break;
        case 2:
            list.Display();
            break;
        case 3:
            list.Search(getName());
            break;
        case 4:
            list.Update(getName());
            break;
        case 5:
            list.Delete(getName());
            break;
        case 6:
            list.Count();
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
