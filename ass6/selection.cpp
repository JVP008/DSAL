#include<bits/stdc++.h>
using namespace std;
int main()
{
    // range formula — min + (rand() % (max-min+1))
    //bubble sort!
    int arr[10];
    srand(time(0));
    for (int i = 0;i<10;i++){
        arr[i] = 300 + (rand() % (500-300+1));
    }
    cout<<"Unsorted Array: ";
    for (int i = 0;i<10;i++){
        cout << *(arr+i)<<" ";
    }

    for (int i = 0;i<10;i++){
        int min = i;
        int temp = 0;
        for (int j=i+1;j<10;j++){
            if (arr[j]<arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    cout<<endl;
    cout<<"size: "<<sizeof(arr);
    cout<<endl <<"Sorted Array: ";
    for (int i = 0;i<10;i++){
        cout<< *(arr+i)<<" ";
    }
    return 0;
}
