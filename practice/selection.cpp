#include<bits/stdc++.h>
using namespace std;
void selection(int arr[],int n){
    for (int i = 0;i<n;i++){
        int min_index = i;
        for (int j = i+1;j<n;j++){
            if (arr[min_index]>arr[j]){
                min_index = j;
            // break;  this is stupid like we want THE SMALLEST
            }
        }  
        //no change -> not found
        if (min_index!=i){
            swap(arr[min_index],arr[i]);
        }
    }
}
int main (){
    int arr[] = {5,3,4,2,1,5,3,4,2,1,5,3,4,2,1,5,3,4,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    selection(arr,size);
    for (int i =0;i<size;i++){
        cout<<arr[i];
    }
    return 0;
}
