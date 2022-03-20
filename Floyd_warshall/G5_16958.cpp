#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int index;
    int type;
    int x, y;
};
int cost[1001][1001];
int main()
{
    cout.tie(0);
    int n, t;
    cin >> n >> t;
    int type, x, y;
    vector<Data> v;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> type >> x >> y;
        v.push_back({i + 1, type, x, y});
    }
    const int INF = 1e9;
    for (int i = 0 ; i <= 1000 ; ++i)
    {
        for (int j = 0 ; j <= 1000 ; ++j)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }   
    }
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = i + 1 ; j < n ; ++j)
        {
            int start = v[i].index;
            int end = v[j].index;
            if (v[i].type == 1 && v[j].type == 1)
            {
                cost[start][end] = min(abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y), t);
                cost[end][start] = min(abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y), t);
            }
            else
            {
                cost[start][end] = abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
                cost[end][start] = abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
            }
        }   
    }
    for (int k = 1 ; k <= n ; ++k)
    {
        for (int i = 1 ; i <= n ; ++i)
        {
            for (int j = 1 ; j <= n ; ++j)
            {
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
            }   
        }
    }
    int m;
    cin >> m;
    int a, b;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b;
        cout << cost[a][b] << '\n';
    }
}