#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int arr[], int n)
{
    if (n == 1)
        return ;
    for (int i = 0 ; i < n - 1 ; ++i)
        if (arr[i] > arr[i + 1])
            swap(&arr[i], &arr[i + 1]);
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {9, 6, 2, 12, 11, 9, 3, 7};

    bubbleSort(arr, 8);
    for (int i = 0 ; i < 8 ; ++i)
        cout << arr[i] << ' ';
}