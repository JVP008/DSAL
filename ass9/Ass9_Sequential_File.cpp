#include <bits/stdc++.h>
using namespace std;

class Record
{
public:
    int roll;
    string name;
    float marks;
};

// file name where all records are stored
string fileName = "records.txt";

int getx()
{
    int x;
    cout << "Enter the roll number: ";
    cin >> x;
    return x;
}

class SequentialFile
{
public:
    // check if roll number is already in file
    bool Exists(int roll)
    {
        ifstream fin(fileName.c_str());
        Record r;
        while (fin >> r.roll >> r.name >> r.marks)
        {
            if (r.roll == roll)
            {
                return true;
            }
        }
        return false;
    }
    // Append new record at the end of file
    void Append(int roll)
    {
        if (Exists(roll))
        {
            cout << "Record already exists\n";
            return;
        }
        Record r;
        r.roll = roll;
        cout << "Enter the name: ";
        cin >> r.name;
        cout << "Enter the marks: ";
        cin >> r.marks;
        ofstream fout(fileName.c_str(), ios::app);
        fout << r.roll << " " << r.name << " " << r.marks << "\n";
        cout << "Record Added Successfully\n";
    }
    // Display all records
    void Display()
    {
        ifstream fin(fileName.c_str());
        Record r;
        bool found = false;
        while (fin >> r.roll >> r.name >> r.marks)
        {
            cout << "Roll: " << r.roll << "  Name: " << r.name << "  Marks: " << r.marks << "\n";
            found = true;
        }
        if (!found)
        {
            cout << "No Records Found\n";
        }
    }
    // Search a record
    void Search(int roll)
    {
        ifstream fin(fileName.c_str());
        Record r;
        while (fin >> r.roll >> r.name >> r.marks)
        {
            if (r.roll == roll)
            {
                cout << "Record Found!!\n";
                cout << "Roll: " << r.roll << "  Name: " << r.name << "  Marks: " << r.marks << "\n";
                return;
            }
        }
        cout << "Record Not Found\n";
    }
    // Delete a record
    void Delete(int roll)
    {
        ifstream fin(fileName.c_str());
        ofstream fout("temp.txt");
        Record r;
        bool found = false;
        while (fin >> r.roll >> r.name >> r.marks)
        {
            if (r.roll == roll)
            {
                found = true;
            }
            else
            {
                fout << r.roll << " " << r.name << " " << r.marks << "\n";
            }
        }
        fin.close();
        fout.close();
        remove(fileName.c_str());
        rename("temp.txt", fileName.c_str());
        if (found)
        {
            cout << "Deleted Successfully\n";
        }
        else
        {
            cout << "Record Not Found\n";
        }
    }
};

int main()
{
    int ch = 1;
    SequentialFile sf;
    while (ch != 0)
    {
        int choice;
        cout << "Enter 1 to add a record\n";
        cout << "Enter 2 to display all records\n";
        cout << "Enter 3 to search a record\n";
        cout << "Enter 4 to delete a record\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sf.Append(getx());
            break;
        case 2:
            sf.Display();
            break;
        case 3:
            sf.Search(getx());
            break;
        case 4:
            sf.Delete(getx());
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
