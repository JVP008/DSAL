#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<filesystem>
using namespace std;

int getx()
{
    int x;
    cout << "Enter the roll number: ";
    cin >> x;
    return x;
}

class Student{
    public:
    string name;
    int roll;
};
string filename = "studdb";
class Studsystem{
    Student s;
    public:
    void addstudent(){
        ofstream fout(filename,ios::app);
        cout<<"Enter roll: ";
        cin>>s.roll;
        cout<<"Enter Name: ";
        cin>>s.name;
        fout<<s.roll<<" "<<s.name<<"\n";
    }
    void removestudent(int roll){
        string file = "temp";
        ofstream fout(file,ios::app);
        ifstream fin(filename,ios::in);
        bool found = false;
        while (fin>>s.roll>>s.name){
            if (s.roll == roll){
                cout<<"found\n";
                found = true;
                continue;
            }
            fout<<s.roll<<" "<<s.name<<"\n";
        }
        fin.close();
        fout.close();
        filesystem::remove(filename);
        filesystem::rename("temp",filename);
        if (found){
            cout<<"Deleted Successfully\n";
        }
        else{
            cout<<"No such entry\n";
        }
    }
    void Display(){
        ifstream fin(filename,ios::in);
        while (fin>>s.roll>>s.name){
            cout<<s.roll<<" "<<s.name;
        }
    }
        

};
int main (){
    Studsystem ss;
    int ch = 1;
    while (ch != 0)
    {
        int choice;
        cout << "Enter 1 to add a record\n";
        cout << "Enter 2 to display all records\n";
        cout << "Enter 3 to delete a record\n";
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ss.addstudent();
            break;
        case 2:
            ss.Display();
            break;
        case 3:
            ss.removestudent(getx());
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
