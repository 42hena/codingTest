#include <bits/stdc++.h>
using namespace std;
int n, m;
int graph[501][501];
int dist[501][501];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct Data
{
    int x, y, w;
    bool operator<(const struct Data &copy)const
    {
        return w > copy.w;
    }
};

void dijkstra()
{
    dist[0][0] = 0;
    priority_queue<Data> pq;

    pq.push({0, 0, 0});
    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int nowCost = pq.top().w;
        pq.pop();
        if (x == 500 && y == 500)
            break;
        if (dist[x][y] < nowCost)
            continue;
        // cout << x << ' ' << y  << ' '<< nowCost << '\n';
        for (int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextCost = nowCost;
            if (nx < 0 || nx > 500 || ny < 0 || ny > 500 || graph[nx][ny] == 2)
                continue;
            if (graph[nx][ny] == 1)
                nextCost++;
            if (nextCost < dist[nx][ny])
            {
                dist[nx][ny] = nextCost;
                pq.push({nx, ny, nextCost});
            }
        }
    }
    if (dist[500][500] == 2147384647)
        cout << -1;
    else
        cout << dist[500][500];

}
int main()
{
    
    for (int i = 0 ; i <= 500 ; ++i)
        for (int j = 0 ; j <= 500 ; ++j)
            dist[i][j] = 10000000;

    int x1, y1, x2, y2;
    cin >> n;
    for (int k = 0 ; k < n ; ++k){
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        if (y1 > y2)
        {
            int tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        // cout << x1 << y1 << x2 << y2 << '\n';
        for (int i = x1 ; i <= x2 ; ++i)
            for (int j = y1 ; j <= y2 ; ++j)
                graph[i][j] = 1;
    }

    cin >> m;
    for (int k = 0 ; k < m ; ++k){
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
        {
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        if (y1 > y2)
        {
            int tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        for (int i = x1 ; i <= x2 ; ++i)
            for (int j = y1 ; j <= y2 ; ++j)
                graph[i][j] = 2;
    }

    dijkstra();
}