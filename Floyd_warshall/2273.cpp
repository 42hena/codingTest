#include <bits/stdc++.h>
using namespace std;

#define MAX 257
int n, m;
int cost1[MAX][MAX];
int cost2[MAX][MAX];

void InitCostArray()
{
    for (int i = 0 ; i < m ; ++i)
    {
        int a, b;
        cin >> a >> b;
        cost1[a][b] = 1;
        cost2[b][a] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            cost1[i][j] = cost2[i][j]  = 1e9;
            if (i == j)
            {
                cost1[i][j] = 0;
                cost2[i][j] = 0;
            }
        }
    }

    InitCostArray();

    for (int k = 1 ; k < n + 1 ; ++k)
    {
        for (int i = 1 ; i < n + 1 ; ++i)
        {
            for (int j = 1 ; j < n + 1 ; ++j)
            {
                cost1[i][j] = min(cost1[i][j], cost1[i][k] + cost1[k][j]);
                cost2[i][j] = min(cost2[i][j], cost2[i][k] + cost2[k][j]);
            }
        }
    }

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            printf(" %10d", cost1[i][j]);
        }
        printf("\n");   
    }

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            printf(" %10d", cost2[i][j]);
        }
        printf("\n");   
    }

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        int front = 0;
        int dontknow = 0;
        int back = 0;
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            if (i == j)
                continue;
            if (cost1[i][j] != 1e9 && cost2[i][j] == 1e9)
                back++;
            if (cost1[i][j] == 1e9 && cost2[i][j] != 1e9)
                front++;
            
        }
        cout << front + 1 << ' ' << n - back << '\n';
    }
    
    

}