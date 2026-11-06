#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int roll;
    string name;
    string branch;
    float marks;
    friend class StudentRecord;
};

int getRoll()
{
    int roll;
    cout << "Enter the roll number: ";
    cin >> roll;
    return roll;
}

string getName()
{
    string name;
    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, name);
    return name;
}

class StudentRecord
{
    private:
        Student list[50];
        int n;

public:
    StudentRecord() : n(0) {}
    bool isEmpty()
    {
        if (n == 0)
        {
            return true;
        }
        return false;
    }
    void Show(int i)
    {
        cout << "Roll No: " << list[i].roll << "\n";
        cout << "Name: " << list[i].name << "\n";
        cout << "Branch: " << list[i].branch << "\n";
        cout << "Marks: " << list[i].marks << "\n";
    }
    // Add a new student record
    void AddStudent()
    {
        if (n == 50)
        {
            cout << "Record is Full\n";
            return;
        }
        cout << "Enter roll number: ";
        cin >> list[n].roll;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, list[n].name);
        cout << "Enter branch: ";
        getline(cin, list[n].branch);
        cout << "Enter marks: ";
        cin >> list[n].marks;
        n++;
        cout << "Record Added\n";
    }
    // Display all the records
    void Display()
    {
        if (isEmpty())
        {
            cout << "No Records Found\n";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "Student " << i + 1 << "\n";
            Show(i);
        }
    }
    // Linear Search using roll number
    void SearchByRoll(int roll)
    {
        for (int i = 0; i < n; i++)
        {
            if (list[i].roll == roll)
            {
                cout << "Student Found!!\n";
                Show(i);
                return;
            }
        }
        cout << "No student with roll number " << roll << "\n";
    }
    // Linear Search using name
    void SearchByName(string name)
    {
        for (int i = 0; i < n; i++)
        {
            if (list[i].name == name)
            {
                cout << "Student Found!!\n";
                Show(i);
                return;
            }
        }
        cout << "No student with name " << name << "\n";
    }
};

int main()
{
    int ch = 1;
    StudentRecord rec;
    while (ch != 0)
    {
        int choice;
        cout << "Enter 1 to add a student\n";
        cout << "Enter 2 to display all students\n";
        cout << "Enter 3 to search by roll number\n";
        cout << "Enter 4 to search by name\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            rec.AddStudent();
            break;
        case 2:
            rec.Display();
            break;
        case 3:
            rec.SearchByRoll(getRoll());
            break;
        case 4:
            rec.SearchByName(getName());
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
