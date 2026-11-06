#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : next(NULL) {}
};
Node *getNode(int x)
{
    Node *newnode = new Node();
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

class HashTable
{
    int size;
    Node *table[10];

public:
    HashTable() : size(10)
    {
        for (int i = 0; i < size; i++)
        {
            table[i] = NULL;
        }
    }
    int hashFunction(int x)
    {
        return x % size;
    }
    // Insert Element
    void Insert(int x)
    {
        if (x < 0)
        {
            cout << "Only positive values allowed\n";
            return;
        }
        int index = hashFunction(x);
        Node *newnode = getNode(x);
        if (table[index] == NULL)
        {
            table[index] = newnode;
        }
        else
        {
            Node *temp = table[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cout << "Inserted at index " << index << "\n";
    }
    // Search Element
    void Search(int x)
    {
        int index = hashFunction(x);
        Node *temp = table[index];
        while (temp != NULL && temp->data != x)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Element Not in Table\n";
        }
        else
        {
            cout << "Element Found at index " << index << "\n";
        }
    }
    // Display the table
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " -> ";
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main()
{
    int ch = 1;
    HashTable ht;
    while (ch != 0)
    {
        int choice;
        cout << "Enter 1 to insert\n";
        cout << "Enter 2 to search\n";
        cout << "Enter 3 to display\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ht.Insert(getx());
            break;
        case 2:
            ht.Search(getx());
            break;
        case 3:
            ht.Display();
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
