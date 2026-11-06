// A. Implement Linear Search and Binary Search Algorithm to search an element in the list 

#include<bits/stdc++.h>
using namespace std;
#define size 10
void ls (int arr[], int i,int target){
    while(i<size){
        if (arr[i]==target){
            cout<<"\nElement Found\n";
            return ;
        }
        i+=1;
    }
    cout<<"\nElement Not Found\n";
}

int main (){

    int target = 10;
    int arr[size] = {7,4,5,6,8,9,2,1,10,3};
    //array quick view
    for (int i : arr){
        cout<<i<<" ";
    }
    //perform linear search on sorted array : complexity -> O (n);
    ls (arr,0,target);
    //print
    cout<<"@Piece out!";

    return 0;
}
