#include<bits/stdc++.h>
using namespace std;
#define size 10

struct Node
{
    int data;
    Node*next;
};
Node* table[size];
// int hashtable[size];

void initializeChain() {

    for (int i = 0; i < size; i++)
        table[i] = NULL;
}
// void initialize(){
//     for (int i = 0;i<size;i++){
//         hashtable[i] = -1;
//     }
// }
int hashfunction(int key){
    return key%size;
}
void insertChain(int key) {

    int index = hashfunction(key);

    Node* n = new Node{key, table[index]};
    //the above line is equivalent to:
    //n->data = key
    //n->next = table[index]
    table[index] = n;
}
void displayChain() {

    for (int i = 0; i < size; i++) {

        cout << i << " -> ";

        Node* temp = table[i];

        while (temp != NULL) {

            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}
bool searchChain(int key) {

    int index = hashfunction(key);

    Node* temp = table[index];

    while (temp != NULL) {

        if (temp->data == key)
            return true;

        temp = temp->next;
    }

    return false;
}
int main (){
    displayChain();
    for (int i =0;i<size;i++){
        cout<<"\nEnter Keys\n";
        cin>>i;
        insertChain(i);
    }
    displayChain();
    cout<<"\n";
    cout<<searchChain(99);
    return 0;
}
