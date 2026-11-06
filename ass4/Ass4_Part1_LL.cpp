/* Problem Stmt : A. Implement Queue using a Linked LIst to perform basic operations such
as Enqueue, Dequeue, Front, Display, and Check whether Queue is Empty or Full.
*/

#include <bits/stdc++.h>
using namespace std;

class QNode
{
private:
    int data{};
    QNode *next;

public:
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
    friend class Queue;
};
class Queue
{
private:
    QNode *front;
    QNode *rear;

public:
Queue() : front(nullptr), rear(nullptr) {}
bool isEmpty()
{
    if (rear == nullptr)
    {
        return true;
    }
    return false;
}
bool isFull()
{
    if (rear == nullptr)
    {
        return true;
    }
    return false;
}
void Front()
    {
        if (isEmpty())
        {
            cout << "No Element in the Queue to display, do insert if you have time!\n";
            return;
        }
        cout << "Element at the front location is: " << front->data << "\n";
    }
    void Enqueue(int d)
    {
        QNode *newnode = new QNode(d);
        if (isEmpty())
        {
            rear = newnode;
            front = newnode;
        }
        else
        {
            rear ->next = newnode;
            rear = rear->next;
        }
        cout << "Inserted Successfully\n";
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow! try to insert an Element first!\n";
            return;
        }
        cout << "Deleted element: " << front->data << "\n";
        QNode* temp = front;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        delete temp;
        

    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "No Element in the Queue to display!\n";
            return ;
        }
        cout << "Elements in The Queue are: ";
        QNode* temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << ", ";
            temp=temp->next;
        }
    }
};
int main()
{
    Queue queue;
    queue.Enqueue(10);
    queue.Enqueue(10e1);
    queue.Enqueue(10e2);
    queue.Enqueue(10e3);

    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();

    queue.Front();

    queue.Display();
}
