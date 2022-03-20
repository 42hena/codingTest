#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, q;
int cost[101][101];
int main()
{
    cin >> n >> q;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
        {
            cost[i][j] = INF;
            if (i == j)
                cost[i][j] = 0;
        }

    vector<pair<int, int>> horses;
    for (int i = 0 ; i < n ; ++i)
    {
        int e, s;
        cin >> e  >> s;
        horses.push_back({e, s});
    }    

    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)    
        {
            cin >> cost[i][j];
            if (i == j)
                cost[i][j] = 0;
            else
                if (cost[i][j] == -1)
                    cost[i][j] = INF;
        }

    for (int k = 1 ; k <= n ; ++k)
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    vector<pair<int, int>> v;
    for (int i = 0 ; i < q ; ++i)
    {
        int u, k;
        cin >> u >> k;
        v.push_back({u, k});
    }
    // for (int i = 1 ; i <= n ; ++i)
    // {
    //     for (int j = 1 ; j <= n ; ++j)
    //         cout << cost[i][j] << ' ';
    //     cout << '\n';    
    // }
    float dp[101];
    for (int i = 1 ; i <= n ; ++i)
        dp[i] = INF;
    for (int i = 1 ; i <= n ; ++i)
        
    

}