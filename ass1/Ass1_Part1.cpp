#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
bool isEmpty(Node *&head)
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
void insertAtBeginning(Node *&head, int x);

void insertAtEnd(Node *&head, int x);

void insertAtSpecificLocation(Node *&head, int number, int x);

void DeleteAtBeginning(Node *&head);

void DeleteAtEnd(Node *&head);

void DeleteAtSpecificLocation(Node *&head, int x);

void Search(Node *&head, int x);

void Traverse(Node *&head);

void Update(Node *head, int old_value, int updated_value);

// void Reverse();

int main()
{
    Node *head = NULL;
    int ch = 1;
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
        cin >> choice;
        int x;
        int location;
        int old = 5;
        switch (choice)
        {
        case 1:
            cout << "Enter x: ";
            cin >> x;
            insertAtBeginning(head, x);
            break;
        case 2:
            cout << "Enter x: ";
            cin >> x;
            insertAtEnd(head, x);
            break;
        case 3:
            cout << "Enter a data's location\n";
            cin >> location;
            cout << "Enter x: \n";
            cin >> x;
            insertAtSpecificLocation(head, location, x);
            break;
        case 4:
            DeleteAtBeginning(head);
            break;
        case 5:
            DeleteAtEnd(head);
            break;

        case 6:
            cout << "Enter a data's location\n";
            cin >> location;
            DeleteAtSpecificLocation(head, location);
            break;

        case 7:
            cout << "Enter x: \n";
            cin >> x;
            Search(head, x);
            break;
        case 8:
            Traverse(head);
            break;

        case 9:
            cout << "Enter x: \n";
            cin >> x;
            Update(head, old, x);
            break;
        case 10:
            cout << "Try Next Time\n";
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

void insertAtBeginning(Node *&head, int x)
{
    Node *newnode = new Node(x);
    newnode->next = head;
    head = newnode;
}

void Traverse(Node *&head)
{
    if (isEmpty(head))
    {
        cout << "Can't Traverse\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<endl;
        temp = temp->next;
    }
}

void insertAtSpecificLocation(Node *&head, int number, int x)
{
    Node *newnode = new Node(x);
    if (isEmpty(head))
    {
        cout << "Location Does not Exists\n";
        return;
    }
    Node *temp = head;
    while (temp->data != number)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertAtEnd(Node *&head, int x)
{
    Node *newnode = new Node(x);
    if (isEmpty(head))
    {
        head = newnode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void DeleteAtBeginning(Node *&head)
{
    Node *temp = head;
    if (isEmpty(head))
    {
        cout << "Cant Delete\n";
        return;
    }
    head = head->next;
    delete temp;
    temp = NULL;
}

void DeleteAtEnd(Node *&head)
{
    if (isEmpty(head))
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
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void DeleteAtSpecificLocation(Node *&head, int location)
{
    if (isEmpty(head))
    {
        cout << "No element to delete\n";
        return;
    }
    else if (head->data == location)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head->next;
    Node *pre = head;
    while (temp != NULL && temp->data != location)
    {
        pre = temp;        // slow pointer
        temp = temp->next; // fast pointer
    }
    if (temp == NULL)
    {
        cout << "Element Not Found\n";
        return;
    }
    pre->next = temp->next;
    delete temp;
}

void Search(Node *&head, int x)
{
    if (isEmpty(head))
    {
        cout << "No Elements is Present\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL && temp->data != x)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Not Found\n";
        return;
    }
    cout << "Found\n";
}

void Update(Node *head, int old_value, int updated_value)
{
    Node *temp = head;
    while (temp != NULL && temp->data != old_value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Old Value Not Found\n";
    }
    temp->data = updated_value;
}