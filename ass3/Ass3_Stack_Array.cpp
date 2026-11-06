#include <bits/stdc++.h>
#define MAX 10
using namespace std;
bool isFull(int top)
{
    if (top == MAX)
    {
        return true;
    }
    return false;
}
bool isEmpty(int top)
{
    if (top==-1)
    {
        return true;
    }
    return false;
}
void Pop(int *arr,int &top){
    if (isEmpty(top)){
        cout<<"No Element to remove\n";
        return;
    }
    cout<<arr[top]<<" Deleted\n";
    top-=1;
}
void Traverse(int arr[], int top)
{
    if (isEmpty(top)){
        cout<<"Can't Traverse \n";
        return;
    }
    while (top!=-1)
    {
        cout << arr[top]<<" ";
        --top;
    }
    cout<<"\n";
}
void Push(int *arr,int &top,int x){
    if (isFull(top)){
        cout<<"Sorry the Stack is Full\n";
        return;
    }
        top++;
        arr[top]=x;
        cout<<" Wooho! "<<x<< " Element Inserted\n";
}
void Peek(int *arr,int top){
    if (isEmpty(top)){
        cout<<"No Element in Stack\n";
        return;
    }
    cout<<"This is the Peek Element: "<<arr[top]<<"\n";
}

// using array/vector;

int main()
{
    int Stack [MAX];
    int top = -1;
    int x;
    int c =1;
    while(c){
        cout << "Enter 1: Insert Element In a Stack\n";
        cout << "Enter 2: Remove Element From a Stack\n";
        cout << "Enter 3: Traverse the Stack\n";
        cout << "Enter 4: Peek/Top Element\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
            cout<<"Enter an Element: \n";
            cin>>x;
            Push(Stack,top,x);
            break;
            case 2:
            Pop(Stack,top);
            break;
            case 3:
            Traverse(Stack,top);
            cout<<"Traversing Complete\n";
            break;
            case 4:
            Peek(Stack,top);
            break;
            default:
            cout << "Wrong Operation\n";
        }
        cout<<"Continue ? 1 or 0\n";
        cin>>c;
    }
    return 0;
}
