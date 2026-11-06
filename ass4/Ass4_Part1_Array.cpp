/* Problem Stmt : A. Implement Queue using an Array to perform basic operations such 
as Enqueue, Dequeue, Front, Display, and Check whether Queue is Empty or Full. 
*/

#include<bits/stdc++.h>
using namespace std;
#define max 10
class Queue{
    private:
    int arr [max];
    int front {};
    int rear {};

    public:
    Queue (){
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        if (rear == -1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if (rear == max-1){
            return true;
        }
        return false;
    }
    void Front(){
        if (isEmpty()){
            cout<<"No Element in the Queue to display!\n";
            return ;
        }
        cout<<"Element at the front location is: "<<arr[front]<<"\n";
        
    }
    void Enqueue(int data){
        if (isFull()){
            cout<<"Overflow!try to Delete an Element first!\n";
            return;
        }
        if (isEmpty()){
            rear+=1;
            front+=1;
            arr[rear] = data ;
        }
        else{
            rear+=1;
            arr[rear] = data;
        }
        cout<<"Inserted Successfully\n";
        
    }
    void Dequeue(){
        if (isEmpty()){
            cout<<"Underflow! try to insert an Element first!\n";
            return ;
        }
        cout<<"Deleted element: "<<arr[front]<<"\n";
        front+=1;
    }
    void Display (){
        if (isEmpty()){
            cout<<"No Element in the Queue to display!\n";
        }
        cout<<"Elements in The Queue are: ";
        int temp = front;
        while(temp!=rear){
            cout<<arr[temp]<<", ";
            temp+=1;
        }
    }
};
int main (){

    Queue queue;
    queue.Enqueue(10);
    queue.Enqueue(10e1);
    queue.Enqueue(10e2);
    queue.Enqueue(10e3);

    queue.Dequeue();
    queue.Dequeue();

    queue.Front();

    queue.Display();

    return 0;
}
