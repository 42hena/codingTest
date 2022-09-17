#include <bits/stdc++.h>
using namespace std;

#define MAX 301
int cost[MAX][MAX];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    printf("%d %d %d\n", n, m, t);
    for (int s = 1 ; s < n + 1 ; ++s)
    {
        for (int e = 1 ; e < n + 1 ; ++e)
        {
            cost[s][e] = 1e9;
        }   
    }

    for (int i = 0 ; i < m ; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // cout << u << ' ' << v << ' ' << w << '\n';
        cost[u][v] = w;
    }

    // v:via
    // s:start
    // e:end
    for (int v = 1 ; v < n + 1 ; ++v)
    {
        for (int s = 1 ; s < n + 1 ; ++s)
        {
            for (int e = 1 ; e < n + 1 ; ++e)
            {
                cost[s][e] = min(cost[s][e], max(cost[s][v], cost[v][e]));
            }
        }
    }
        
    // for (int s = 1 ; s < n + 1; ++s)
    // {
    //     for (int e = 1 ; e < n + 1 ; ++e)
    //     {
    //         printf(" %10d", cost[s][e]);
    //     }
    //     printf("\n");
    // }
    for (int i = 0 ; i < t ; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (cost[a][b] == 1e9)
            cout << -1 << '\n';
        else
            cout << cost[a][b]<< '\n';
    }
}