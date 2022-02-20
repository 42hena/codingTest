#include <bits/stdc++.h>
using namespace std;
int n, m;
char graph[100][100];
int dist[100][100];

struct Data{
    int x;
    int y;
    int w;
    bool operator<(const struct Data &copy)const
    {
        return w > copy.w;
    }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
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
        // cout << x << ' ' << y << ' ' <<nowCost<< '\n';
        pq.pop();
        if (x == m - 1 && y == n - 1)
            break;
        if (dist[x][y] < nowCost)
            continue;
        for (int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            int nextCost = dist[x][y];
            if (graph[nx][ny] == '1')
                nextCost++;
            if (nextCost < dist[nx][ny])
            {
                dist[nx][ny] = nextCost;
                pq.push({nx, ny, nextCost});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0 ; i < m ; ++i){
        for (int j = 0 ; j < n ; ++j)
        {
            cin >> graph[i][j];
            dist[i][j] = 2147483647;
        }
    }
    dijkstra();
    cout << dist[m -1][n - 1];
}