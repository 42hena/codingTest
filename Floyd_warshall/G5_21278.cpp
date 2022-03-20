#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m;
int cost[101][101];
int main()
{
    cin >> n >> m;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
        {
            cost[i][j] = INF;
            if (i == j)
                cost[i][j] = 0;
        }

    int a, b;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b;
        cost[a][b] = 1;
        cost[b][a] = 1;
    }    

    for (int k = 1 ; k <= n ; ++k)
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    int house1 = 1, house2 = 2;
    int minValue = 1e9;
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = i + 1 ; j <= n ; ++j)
        {
            // i , j가 치킨집이라고 함
            int sum = 0;
            for (int k = 1 ; k <= n ; ++k)
            {
                if (k != i && k != j)
                    sum += min(cost[k][i], cost[k][j]);
            }
            if (sum < minValue)
            {
                minValue = sum;
                house1 = i;
                house2 = j;
            }
        }
    }
    cout << house1 << ' ' << house2 <<' ' << minValue * 2;
}