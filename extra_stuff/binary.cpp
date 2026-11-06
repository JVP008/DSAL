//2. Generate a binary number of given integer and create 
//singly linked list to store the same.
//Example  No 5 =  101
//Linked list Head  🡪 1----0----1

#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node*next;
    Node(){
        next=NULL;
    }
};
int main (){
    int n;
    cout<<"Enter a Number\n";
    cin>>n;

    //logic
    int q =0;
    int r= 0;
    string binary = "";
    while(n>0){
        q = n/2;
        r = n%2;
        n = q;
        binary+=r;
    }
    Node* head = new Node();
    int size = binary.size();
    for (int i = 0;i<size;i++){
        Node* newnode = new Node();
        newnode->data = binary[i];
        newnode->next = head;
        head = newnode; //[]<-[]<-[]<-[]head
   }

   Node* temp = head;
   while(temp->next!=NULL){
    cout<<temp->data<<"----";
    temp = temp->next;
   }
    return 0;
}