#include <bits/stdc++.h>
using namespace std;

int arr[2][100000];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < n; ++j)
                cin >> arr[i][j];
        arr[0][1] += arr[1][0];
        arr[1][1] += arr[0][0];
        for (int j = 2; j < n; ++j)
            for (int i = 0; i < 2; ++i)
            {
                if (i == 0)
                    arr[i][j] = max(max(arr[i][j - 2], arr[i + 1][j - 2]), arr[i + 1][j - 1]) + arr[i][j];
                else
                    arr[i][j] = max(max(arr[i][j - 2], arr[i - 1][j - 2]), arr[i - 1][j - 1]) + arr[i][j];
            }
        cout << max(arr[0][n - 1], arr[1][n - 1]) << '\n';
    }
}