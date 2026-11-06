// A. Implement Linear Search and Binary Search Algorithm to search an element in the list 

#include<bits/stdc++.h>
using namespace std;
#define size 10
void bs (int arr[], int i, int j,int target){
    while(i<=j){
        int mid = i+(j-i)/2;
        if (*(arr+mid) == target){
            cout<<"\nElement Found\n";
            return ;
        }
        else if (*(arr+mid)>target){
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    cout<<"\nElement Not Found\n";
}
void st(int arr[],int n){
    sort(arr,arr+n);
}
int main (){

    int target = -6;
    int arr[size] = {7,4,5,6,8,9,2,1,10};
    //sort first
    st (arr,size);
    //array quick view
    for (int i : arr){
        cout<<i<<" ";
    }
    //perform binary search on sorted array : complexity -> O(logn)
    bs (arr,0,size,target);
    //print
    cout<<"@Piece out!";

    return 0;
}
