#include<bits/stdc++.h>
using namespace std;
void insertion(int arr[],int n){
    for (int i = 1;i<n;i++){
        int j = i;
        while (j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j-=1;
        }   
    }
}
int main (){
    int arr[] = {5,3,4,2,1,5,3,4,2,1,5,3,4,2,1,5,3,4,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertion(arr,size);
    for (int i =0;i<size;i++){
        cout<<arr[i];
    }
    return 0;
}
