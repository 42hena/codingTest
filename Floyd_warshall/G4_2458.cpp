#include <bits/stdc++.h>
using namespace std;
int cost[501][501];
int cost1[501][501];
int main()
{
    int n, m;
    int INF = 1e9;
    cin >> n >> m;
    int v1, v2;

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            if (i == j)
            {
                cost[i][j] = 0;
                cost1[i][j] = 0;
            }
            else
            {
                cost[i][j] = INF;
                cost1[i][j] = INF;
            }
        }
    }
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2;
        cost[v1][v2] = 1;
        cost1[v2][v1] = 1;
    }

    for (int k = 1 ; k < n + 1 ; ++k)
    {
        for (int i = 1 ; i < n + 1 ; ++i)
        {
            for (int j = 1 ; j < n + 1 ; ++j)
            {
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
                cost1[i][j] = min(cost1[i][k] + cost1[k][j], cost1[i][j]);
            }
        }
    }
    // for (int i = 1 ; i < n + 1 ; ++i)
    // {
    //     for (int j = 1 ; j < n + 1 ; ++j)
    //     {
    //         if (cost[i][j] == INF)
    //             cout << 'I' << ' ';
    //         else
    //             cout << cost[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 1 ; i < n + 1 ; ++i)
    // {
    //     for (int j = 1 ; j < n + 1 ; ++j)
    //     {
    //         if (cost1[i][j] == INF)
    //             cout << 'I' << ' ';
    //         else
    //             cout << cost1[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int cnt = 0;
    for (int i = 1 ; i < n + 1 ; ++i)
    {
        bool flag = true;
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            if (cost[i][j] == INF && cost1[i][j] == INF)
                flag = false;
        }
        if (flag)
            cnt++;
    }
    cout << cnt;
}