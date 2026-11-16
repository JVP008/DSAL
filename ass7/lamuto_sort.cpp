#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int s, int e)
{
    int i = s - 1;
    int pivot = arr[e];
    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    i += 1;
    swap(arr[i], arr[e]);
    return i;
}
void quick_sort(int arr[], int s, int e)
{
    if (s > e)
    {
        return;
    }
    int pi = partition(arr, s, e);
    quick_sort(arr, s, pi - 1);
    quick_sort(arr, pi + 1, e);
}
int main()
{
    int n = 15;
    int arr[n] = {9, 8, 6, -1, 4, 5, 7, 8, 22, 1, -21, 7, 1, 0, 5};
    quick_sort(arr, 0, n - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
