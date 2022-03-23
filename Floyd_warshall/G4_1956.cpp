#include <bits/stdc++.h>
using namespace std;
#define FOR(I, E) for (int I = 1 ; I < E + 1 ; ++I)
int n, m;
int cost[401][401];
int v1, v2, w;
int main()
{
    cin >> n >> m;
    const int INF = 1e9;
    FOR(i, n)
        FOR(j, n)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;   
        }

    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;;
        cost[v1][v2] = w;
    }
    FOR(k, n)
        FOR(i, n)
            FOR(j, n)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    int answer = INF;
    FOR(i, n)
        FOR(j, n)
        {
            if (i != j)
                answer = min(answer, cost[i][j] + cost[j][i]);
        }
    if (answer == INF)
        cout << -1;
    else
        cout << answer;
}