#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int index;
    int left, right;
};
int cost[301][301];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    vector<Data> v;
    int x1, x2;
    for (int i = 0; i < n; ++i)
    {
        cin >> x1 >> x2;
        v.push_back({i + 1, x1, x2});
    }
    const int INF = 1e9;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (v[i].right <= v[j].right && v[i].right >= v[j].left)
            {
                cost[v[i].index][v[j].index] = 1;
                cost[v[j].index][v[i].index] = 1;
            }
            if (v[i].right >= v[j].right && v[i].left <= v[j].right)
            {
                cost[v[i].index][v[j].index] = 1;
                cost[v[j].index][v[i].index] = 1;
            }
            // if (v[i].right < v[j].right && v[i].left > v[j].left)
            // {
            //     cost[v[i].index][v[j].index] = 1;
            //     cost[v[j].index][v[i].index] = 1;
            // }
            // if (v[i].right > v[j].right && v[i].left < v[j].left)
            // {
            //     cost[v[i].index][v[j].index] = 1;
            //     cost[v[j].index][v[i].index] = 1;
            // }
            
         
        }
    }

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int j = 1; j <= n; ++j)
    //     {
    //         cout << cost[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);   
            }
        }
    }

    cin >> m;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> x1 >> x2;
        if (cost[x1][x2] == INF)
            cout << -1 << '\n';
        else
            cout << cost[x1][x2] << '\n';
    }
}