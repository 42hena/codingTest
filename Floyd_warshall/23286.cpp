#include <bits/stdc++.h>
using namespace std;

#define MAX 301
int n, m, t;
int cost[MAX][MAX];
int road[MAX][MAX];

void InitCostArray()
{
    for (int i = 0 ; i < m ; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
    }
}

void print()
{
    for (int i = 1; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            printf(" %10d", cost[i][j]);
        }
        printf("\n");   
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> t;
    for (int i = 1 ; i < n + 1 ; ++i)
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            cost[i][j] = 1e9;
            road[i][j] = 1e9;
            if (i == j)
                cost[i][j] = 0;
        }
    InitCostArray();
    
    for (int k = 1 ; k < n + 1 ; ++k)
    {
        for (int i = 1 ; i < n + 1 ; ++i)
        {
            for (int j = 1 ; j < n + 1 ; ++j)
            {
                    cost[i][j] = min(cost[i][j], max(cost[i][k], cost[k][j]));       
            }
        }
        print();
        printf("\n");
    }

    
    for (int i = 1; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            printf(" %10d", cost[i][j]);
        }
        printf("\n");   
    }
}