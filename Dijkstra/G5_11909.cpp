
#include <bits/stdc++.h>
using namespace std;
int n;
int graph[2222][2222];
int dist[2222][2222];

struct Data
{
    int x, y, w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};
int dx[] = {1, 0};
int dy[] = {0, 1};
void dijstra(int sx, int sy)
{
    priority_queue<Data> pq;
    dist[sx][sy] = 0;

    pq.push({sx, sy, 0});

    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int nowCost = pq.top().w;
        pq.pop();
        // cout << x << ' ' << y << ' ' << nowCost << '\n';
        if (dist[x][y] < nowCost)
            continue;
        for (int i = 0 ; i < 2 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextCost = (graph[x][y] <= graph[nx][ny] ? abs(graph[x][y] - graph[nx][ny]) + 1 : 0) + dist[x][y];
            if (nextCost < dist[nx][ny])
            {
                dist[nx][ny] = nextCost;
                pq.push({nx, ny, nextCost});
            }
        }
    }
    cout << dist[n - 1][n - 1];
}

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main(void)
{
    FastIO();
    cin >> n;    
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
        {
            cin >> graph[i][j];
            dist[i][j] = 2147483647;
        }
    
    dijstra(0, 0);
}