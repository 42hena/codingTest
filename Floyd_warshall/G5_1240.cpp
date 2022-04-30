#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF 1e9
int cost[MAX][MAX];

int main()
{
    int n, m;

    cin >> n >> m;
    int v1, v2, w;
    for (int i = 1 ; i < MAX ; ++i)
    {
        for (int j = 1 ; j < MAX ; ++j)
        {
            cost[i][j] = INF;
            if (i == j)
                cost[i][j] = 0;
        }   
    }

    for (int i = 0 ; i < n - 1 ; ++i)
    {
        cin >> v1 >> v2 >> w;
        cost[v1][v2] = w;
        cost[v2][v1] = w;
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
        cin >> v1 >> v2;
        cout << cost[v1][v2] << '\n';   
    }
}