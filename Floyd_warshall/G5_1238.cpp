#include <bits/stdc++.h>
using namespace std;
int dist[1001][1001];
void FastIO()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
}
int main()
{
    FastIO();
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
            dist[i][j] = 10000000;
    for (int i = 1 ; i <= n ; ++i)
        dist[i][i] = 0;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        dist[v1][v2] = w;
    }
    for (int k = 1 ; k <= n ; ++k)
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    int maxVal = 0;
    // for (int i = 1 ; i <= n ; ++i){
    //     for (int j = 1 ; j <= n ; ++j){
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1 ; i <= n ; ++i)
        maxVal = max(maxVal, dist[i][x] + dist[x][i]);
    cout << maxVal;
}