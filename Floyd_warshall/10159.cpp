#include <bits/stdc++.h>
using namespace std;

int cost1[101][101];
int cost2[101][101];


int main()
{
    int n; // 물건의 개수
    int m; // 물건 측정 개수
    cin >> n >> m;
    for (int i = 1 ; i < n + 1 ; ++i)
    {
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            cost1[i][j] = cost2[i][j] = 1e9;            
            if (i == j)
                cost1[i][j] = cost2[i][j] = 0;
        }
    }

    for (int i = 0 ; i < m ; ++i)
    {
        int a, b;
        cin >> a >> b;
        cost1[a][b] = 1;
        cost2[b][a] = 1;
    }

    for (int k = 1 ; k < n + 1 ; ++k)
        for (int i = 1 ; i < n + 1 ; ++i)
        {
            for (int j = 1 ; j < n + 1 ; ++j)
            {
                cost1[i][j] = min(cost1[i][j], cost1[i][k] + cost1[k][j]);
                cost2[i][j] = min(cost2[i][j], cost2[i][k] + cost2[k][j]);
            }
        }
        
    for (int i = 1 ; i < n + 1 ; ++i)
    {
        int cnt = 0;
        for (int j = 1 ; j < n + 1 ; ++j)
            if (cost1[i][j] == 1e9 && cost2[i][j] == 1e9)
                cnt++;
        cout << cnt << '\n';
    }
}