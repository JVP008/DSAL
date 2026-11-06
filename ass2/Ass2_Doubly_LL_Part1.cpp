#include <bits/stdc++.h>
using namespace std;

class Dnode
{
public:
    int data;
    Dnode *next;
    Dnode *prev;
    Dnode() : next(NULL), prev(NULL) {}
};
Dnode *getNode(int x)
{
    Dnode *newnode = new Dnode();
    newnode->data = x;
    return newnode;
}

int getx()
{
    int x;
    cout << "Enter the value: ";
    cin >> x;
    return x;
}
 
class DoublyLinkedList
{
    Dnode *head;

public:
    DoublyLinkedList() : head(NULL) {}
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    // InsertElement at Beginning
    void InsertatBeginning(int x)
    {
        Dnode *newnode = getNode(x);
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode; 
        head = newnode;
    }
    // InsertElement at End
    void InsertatEnd(int x)
    {
        Dnode *newnode = getNode(x);
        if (head == NULL)
        {
            head = newnode;
            return;
        }
        Dnode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    // InsertElement at Specific Position
    void InsertatSL(int location, int x)
    {
        Dnode *temp = head;
        while (temp != NULL && temp->data != location)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        { 
            cout << "Location not found\n";
            return;
        }
        temp->data = x;
        cout << "Inserted Successfully\n";
    }
    // Delete at Beginning
    void DeleteatBeginning()
    {
        if (isEmpty())
        {
            cout << "Can't Delete\n";
            return;
        }
        Dnode *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }
    // Delete at End
    void DeleteatEnd()
    {
        if (isEmpty())
        {
            cout << "Cant Delete\n";
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Dnode *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    // Delete at Specific Position
    void DeleteatSL(int location)
    {
        if (isEmpty())
        {
            cout << "Cant Delete\n";
            return;
        }
        Dnode *temp = head;
        while (temp->next != NULL && temp->next->data != location)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Location not found\n";
            return;
        }

        Dnode *toDelete = temp->next;
        temp->next = toDelete->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }
        delete toDelete;
        cout << "Deleted Successfully\n";
    }
    // Search in the linkedList
    void Search(int x)
    {
        Dnode *temp = head;
        while (temp != NULL && temp->data != x)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Element Not in List:\n";
        }
        else
        {
            cout << "Element Found!!\n";
        }
    }
    // Traverse the Linked list
    void Traverse()
    {
        Dnode *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    // Update existing Value
    void Update(int val, int x)
    {
        Dnode *temp = head;
        while (temp != NULL && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Value not found\n";
            return;
        }
        temp->data = x;
    }
    void Reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            cout << "Reverse Failed";
            return;
        }
        Dnode *prev = NULL;
        Dnode *curr = head;

        while (curr != NULL)
        {
            prev = curr->prev;
            curr->prev = curr->next;
            curr->next = prev;
            curr = curr->prev;
        }
        head = prev->prev;
    }
};

int main()
{
    int ch = 1;
    DoublyLinkedList dll;
    while (ch != 0)
    {
        int choice;
        cout << "Enter 1 to insert at beginning\n";
        cout << "Enter 2 to insert at end\n";
        cout << "Enter 3 to insert at specific location\n";
        cout << "Enter 4 to delete at beginning\n";
        cout << "Enter 5 to delete at end\n";
        cout << "Enter 6 to delete at specific location\n";
        cout << "Enter 7 to search\n";
        cout << "Enter 8 to traverse\n";
        cout << "Enter 9 to update\n";
        cout << "Enter 10 to reverse\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        int location;
        int old = 5;
        switch (choice)
        {
        case 1:
            dll.InsertatBeginning(getx());
            break;
        case 2:
            dll.InsertatEnd(getx());
            break;
        case 3:
            cout << "Enter a data's location\n";
            cin >> location;
            dll.InsertatSL(location, getx());
            break;
        case 4:
            dll.DeleteatBeginning();
            break;
        case 5:
            dll.DeleteatEnd();
            break;

        case 6:
            cout << "Enter a data's location\n";
            cin >> location;
            dll.DeleteatSL(location);
            break;

        case 7:
            dll.Search(getx());
            break;
        case 8:
            dll.Traverse();
            break;

        case 9:
            dll.Update(old, getx());
            break;
        case 10:
            dll.Reverse();
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