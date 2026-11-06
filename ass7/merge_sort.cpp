#include<bits/stdc++.h>
using namespace std;

//divide till l not become H 
//while merging compare elements then add to array!

void merge(int arr[],int low,int mid,int high){
    int l = low;
    int h = mid+1;
    int k = 0;
    int temp[high-low+1];
    while (l<=mid && h <= high){
        if (arr[l]>arr[h]){
           temp[k] = arr[h];
           h+=1;
        }
        else{
            temp[k] = arr[l];
            l+=1;
        }
        k+=1;
    }
     while (l <= mid) {
        temp[k] = arr[l];
        l++;
        k++;
    }
    while (h <= high) {
        temp[k] = arr[h];
        h++;
        k++;
    }
    for (int i = 0; i < k; i++) {
        arr[low + i] = temp[i];
    }

}
void merge_sort(int arr[],int low,int high){
    if (low>=high){
        return ;
    }
    int mid = low + (high-low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main (){
    int n = 10;
    int arr[n] = {9,8,6,4,3,7,1,2,0,5};
    merge_sort(arr,0,n-1);
    for (auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}
