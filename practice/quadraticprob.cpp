#include<bits/stdc++.h>
using namespace std;
#define size 10
int hashtable[size];
void initialize(){
    for (int i = 0;i<size;i++){
        hashtable[i] = -1;
    }
}
int hashfunction(int key){
    return key%size;
}
void Quadratic_Probing(int key){
    int index = hashfunction(key);
    for (int i=0;i<size;i++){
        int pos = (index+i*i) % size;
        if (hashtable[pos] == -1){
            hashtable[pos] = key;
            return;
        }
    }
    cout<<"FULL\n";
    return;
}
void display(){
    for (auto it:hashtable){
        cout<<it<<" ";
    }
}
bool searchquad(int key) {
    int index = hashfunction(key);

    for (int i = 0; i < size; i++) {

        int pos = (index + i*i) % size;
        if (hashtable[pos] == -1)
            return false;

        if (hashtable[pos] == key)
            return true;
    }

    return false;
}
int main (){
    initialize();
    display();
    for (auto i : hashtable){
        cout<<"\nEnter Keys\n";
        cin>>i;
        Quadratic_Probing(i);
    }
    display();
    cout<<"\n";
    cout<<searchquad(99);
    return 0;
}
