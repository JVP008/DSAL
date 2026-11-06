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
// Resuable Stack {Template}!
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }

    void Peek()
    {
        if (isEmpty())
        {
            cout << "No Element in Stack";
            return;
        }
        cout << "Peek Element is: " << top->data<<endl;
    }
    void Push(int x)
    {
        Node *n = new Node(x);
        n->next = top;
        top = n;
    }
    void Pop()
    {
        Node*temp = top;
        if (isEmpty())
        {
        cout << "Can't Pop!!";
        return;
        }
        else{
        cout << "Element that got popped: ";
        cout<<top->data<<endl;
        top = top->next;
        }
        delete temp;
        cout<<"Memory Freed!";
    }

    void Traverse()
    {
        cout << "These are the elements: ";
        Node*temp = top;
        while (temp!= NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{

    Stack stack;
    int x;
    int c = 1;
    while (c)
    {
        cout << "Enter 1: Insert Element In a Stack\n";
        cout << "Enter 2: Remove Element From a Stack\n";
        cout << "Enter 3: Traverse the Stack\n";
        cout << "Enter 4: Peek/Top Element\n";
        cout << "Enter Your Choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter an Element: \n";
            cin >> x;
            stack.Push(x);
            break;
        case 2:
            stack.Pop();
            break;
        case 3:
            cout << "Traversing Complete\n";
            stack.Traverse();
            break;
        case 4:
            stack.Peek();
            break;
        default:
            cout << "Wrong Operation\n";
        }
        cout << "Continue ? 1 or 0\n";
        cin >> c;
    }

    return 0;
}