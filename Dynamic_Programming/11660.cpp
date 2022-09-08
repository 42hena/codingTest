#include <bits/stdc++.h>
using namespace std;

int arr[(1<<10) + 1][(1<<10) + 1];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int n, m;
    cin >> n >> m;

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            arr[i][j] += arr[i][j - 1]; 
        }
    }
    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            arr[j][i] += arr[j  - 1][i]; 
        }
    }


    for (int i = 0 ; i < m ; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2] + arr[x1 - 1][y1 - 1] - arr[x1-1][y2] - arr[x2][y1-1] << '\n';
    }
}