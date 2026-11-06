#include<bits/stdc++.h>
using namespace std;
int main()
{
    // range formula — min + (rand() % (max-min+1))
    // i,j ; if i>j swap
    //bubble sort!
    int arr[10];
    srand(time(0));
    for (int i = 0;i<10;i++){
        arr[i] = 300 + (rand() % (500-300+1));
    }

    for (int i = 0;i<10;i++){
        cout << *(arr+i)<<" ";
    }

    for (int i = 1;i<10;i++){
        bool swapped = false;
        for (int j=0;j<10;j++){
            int temp = 0;
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    cout<<endl;
    int i = 0;
    while (i<10){
        cout<<arr[i]<<" ";
        i++;
    }
    return 0;
}
