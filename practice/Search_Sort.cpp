#include <iostream>
#include <string>
using namespace std;
/*
Create a student database of at least 5 SEIT students, each having:
• Roll Number (Integer)
• Name (String)
• SGPA (Float)
Perform the following operations on the array of structure:
a. Sort students by roll number (ascending order) using Bubble Sort.
b. Sort students alphabetically by name using Insertion Sort.
c. Sort students by SGPA in descending order using Quick Sort to get top 10 toppers.
d. Search for students by SGPA using Linear Search and display all matches.
e. Search for student(s) by name using non-recursive Binary Search, display all partial matches.
*/

// creating Model -> Student
class Student
{
private:
    string name;
    int roll;
    float sgpa;

public:
    Student() : name(""), roll(-1), sgpa(-1) {}
    Student(int roll, string name, float sgpa) : name(name), roll(roll), sgpa(sgpa) {}
    friend class StudentMang;
};
class StudentMang
{
private:
    int index = 0;
    Student arr[5] = {};
    void sort_algo() {}
    bool search_algo(int roll)
    {
        int size = sizeof(arr) / sizeof(arr[0]);
        for (int i = 0; i < size; i++)
        {
            if (arr[i].roll == roll)
            {
                return true;
            }
        }
        return false;
    }

public:
    void displayStudents()
    {
        int size = sizeof(arr) / sizeof(arr[0]);
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].name << " ";
            cout << arr[i].roll << " ";
            cout << arr[i].sgpa << "\n";
        }
    }
    void searchStudent(int roll)
    {
        if (search_algo(roll))
        {
            cout << "Found\n";
            return;
        }
        cout << "Not Found\n";
    }

    void deleteStudent(int roll)
    {
        if (roll < 0)
        {
            cout << "Not Possible to delete\n";
            return;
        }
        int size = sizeof(arr) / sizeof(arr[0]);
        Student temp[size];
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].roll != roll)
            {
                temp[j] = arr[i];
                j += 1;
            }
        }
        size = sizeof(temp) / sizeof(temp[0]);
        for (int i = 0; i < j; i++)
        {
            arr[i] = temp[i];
        }
        index += 1;
    }
    void addStudent(int roll, string name, float sgpa)
    {
        Student s(roll, name, sgpa);
        if (index == size(arr))
        {
            cout << "Maximum Capacity of Students Reached\n";
        }
        else
        {
            arr[index] = s;
            cout << "Student Inserted Successfully\n";
        }
        index+=1;
    }
};
int main()
{

    StudentMang sm;
    int ch;
    while (true)
    {
        int roll = {};
        string name = {};
        float sgpa = {};
        cout << "Enter 1 to add Student: \n";
        cout << "Enter 2 to search Student: \n";
        cout << "Enter 3 to display Student: \n";
        cout << "Enter 4 to delete Student: \n";
        cout << "Enter 5 to Exit: \n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter roll:\n";
            cin >> roll;
            cout << "Enter name:\n";
            cin >> name;
            cout << "Enter sgpa:\n";
            cin >> sgpa;
            sm.addStudent(roll, name, sgpa);
            break;
        case 2:
            cout << "Enter Roll Number to Search\n";
            cin >> roll;
            sm.searchStudent(roll);
            break;
        case 3:
            sm.displayStudents();
            break;
        case 4:
            cout << "Enter Roll Number to Delete\n";
            cin >> roll;
            sm.deleteStudent(roll);
            break;
        case 5:
            cout << "Exiting the System......\n";
            return 0;
        default:
            cout << "Enter correct choice!\n";
            break;
        }
    }
}
