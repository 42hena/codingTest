#include <bits/stdc++.h>
using namespace std;

int cost[501][501];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            cin >> cost[i][j];
        }
    }
    for (int k = 1 ; k < n + 1 ; ++k)
    {
        for (int i = 1 ; i < n + 1 ; ++i)
        {
            for (int j = 1 ; j < n + 1 ; ++j)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    for (int i = 0 ; i < m ; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (cost[a][b] <= c)
        {
            cout << "Enjoy other party\n";   
        }   
        else
        {
            cout << "Stay here\n";   
        }
    }
}