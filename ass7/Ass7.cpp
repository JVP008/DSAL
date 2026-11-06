//Quick-Sort!!
// [7,2,3,5,10,9,6,3,10,1]
#include<iostream>
using namespace std;
int partiton (int arr[],int s,int e){
    
    int pivot = arr[s];
    int cnt = 0;
    
    for (int i = s+1;i<e;i++){
        if (arr[i]<=pivot){
            cnt+=1;
        }
    }
    //calculate correct position
    int pivot_index = cnt + s;
    
    swap(arr[pivot_index],arr[s]);
    int i = s;
    int j = e;
    //fix left and right side
    while (i<pivot_index && j > pivot_index){
        while (arr[i]<=pivot){
            i+=1;
        }
        while (arr[j]>pivot){
            j-=1;
        }
        if (i<pivot_index && j>pivot_index){ //prevents from runtime errors
            swap (arr[i],arr[j]);
            i+=1;
            j-=1;
        }
    }
    return pivot_index;
}
void quick_sort(int arr[],int s,int e){
    if (s>=e){ //what if there are two elements remaining
        return ;
    }
    int pindex = partiton(arr,s,e);
    //left
    quick_sort(arr,s,pindex-1);
    //right
    quick_sort(arr,pindex+1,e);

}
int main(){
    int arr[10] = {7,2,3,5,10,9,6,3,10,1};
    quick_sort(arr,0,10);
    for (int i =0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
