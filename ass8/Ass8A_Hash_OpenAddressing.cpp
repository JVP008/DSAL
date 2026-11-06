#include <bits/stdc++.h>
using namespace std;

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
    int *table;
    int type; // 1 for linear, 2 for quadratic

public:
    HashTable(int s, int t)
    {
        size = s;
        type = t;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1; // -1 means empty slot
        }
    }
    int hashFunction(int x)
    {
        return x % size;
    }
    // get the index for the i th try
    int probe(int x, int i)
    {
        if (type == 1)
        {
            return (hashFunction(x) + i) % size;
        }
        return (hashFunction(x) + i * i) % size;
    }
    // Insert Element
    void Insert(int x)
    {
        if (x < 0)
        {
            cout << "Only positive values allowed\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            int index = probe(x, i);
            if (table[index] == -1)
            {
                table[index] = x;
                cout << "Inserted at index " << index << "\n";
                return;
            }
        }
        cout << "Can't Insert, no free slot found\n";
    }
    // Search Element
    void Search(int x)
    {
        for (int i = 0; i < size; i++)
        {
            int index = probe(x, i);
            if (table[index] == -1)
            {
                break;
            }
            if (table[index] == x)
            {
                cout << "Element Found at index " << index << "\n";
                return;
            }
        }
        cout << "Element Not in Table\n";
    }
    // Display the table
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " -> ";
            if (table[i] == -1)
            {
                cout << "empty";
            }
            else
            {
                cout << table[i];
            }
            cout << "\n";
        }
    }
    ~HashTable()
    {
        delete[] table;
    }
};

int main()
{
    int ch = 1;
    int type;
    cout << "Enter 1 for Linear Probing\n";
    cout << "Enter 2 for Quadratic Probing\n";
    cout << "Enter Your Choice: ";
    cin >> type;
    if (type != 1 && type != 2)
    {
        cout << "Wrong Choice!\n";
        return 0;
    }
    HashTable ht(10, type);
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
