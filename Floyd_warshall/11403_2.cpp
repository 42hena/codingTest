#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100][100];
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
        {
            arr[i][j] = 1e9;
            int num;
            scanf("%d", &num);
            if (num)
                arr[i][j] = 1;
        }
    for (int k = 0 ; k < n ; ++k)
        for (int i = 0 ; i < n ; ++i)
            for (int j = 0 ; j < n ; ++j)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
    
    for (int i = 0 ; i < n ; ++i)
    {        
        for (int j = 0 ; j < n ; ++j)
        {
            if ((int)1e9 == arr[i][j]) 
                printf("0 ");
            else
                printf("%d ", 1);
        }
        cout << '\n';
    }
}