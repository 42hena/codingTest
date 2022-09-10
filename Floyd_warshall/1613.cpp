#include <bits/stdc++.h>
using namespace std;

#define MAX 400
int n, k;
int cost[MAX + 1][MAX + 1];
void InitCostArray()
{
    for (int i = 1 ; i  < n + 1 ; ++i)
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            cost[i][j] = 1e9;
            if (i == j)
                cost[i][j] = 0;
        }
}

int main()
{
    cin >> n >> k;
    InitCostArray();
    
    for (int i = 0 ; i < k ; ++i)
    {
        int a, b;
        cin >> a >> b;
        cost[a][b] = 1;
    }
    for (int k = 1 ; k < n + 1 ; ++k)
    {
        for (int i = 1 ; i < n + 1 ; ++i)
            for (int j = 1 ; j < n + 1 ; ++j)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
    }

    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            printf(" %9d", cost[i][j]);
        }
        printf("\n");
    }
    int s;
    cin >> s;
    for (int i = 0 ; i < s ; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (cost[a][b] == 1e9 && cost[b][a] == 1e9)
            cout << "0\n";
        else if(cost[a][b] != 1e9)
            cout << "-1\n";
        else
            cout << "1\n";
    }
}