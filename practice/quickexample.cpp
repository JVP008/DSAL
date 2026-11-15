#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int roll;
    string name;
};
class StudentMang
{

private:
    int size;
    int k = 0;

public:
    Student *arr;
    StudentMang()
    {
        size = 5;
        arr = new Student[size];
    }
    void addStudent(int roll, string name)
    {
        if (k == size)
        {
            cout << "Capacity Full!";
        }
        else
        {
            arr[k].roll = roll;
            arr[k].name = name;
            k += 1;
        }
    }
    void partition(int low, int high, int &pi)
    {
        int pivot = arr[high].roll;
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j].roll < pivot)
            {
                i += 1;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        pi = i + 1;
    }
    
    void quickSort(int low, int high)
    {
        if (low < high)
        {
            int pi;
            partition(low, high, pi);

            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    void sort()
    {
        if (size > 1)
        {
            quickSort(0, size - 1);
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i].name << " " << arr[i].roll << "\n";
        }
    }
};

int main()
{
    StudentMang std;
    std.addStudent(67, "Jayesh");
    std.addStudent(77, "Tushar");
    std.addStudent(37, "Priya");
    std.addStudent(47, "Rohan");
    std.addStudent(97, "Ananya");

    cout << "before sorting\n";
    std.display();
    std.sort();
    cout << "after sorting\n";
    std.display();
    return 0;
}
