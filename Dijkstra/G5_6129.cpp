#include <bits/stdc++.h>
using namespace std;
char graph[100][100];
int dist[100][100];

struct Data{
    int x, y, w, d;
    bool operator<(const struct Data &copy)const
    {
        return w > copy.w;
    }
};

int dx[] = {-1, 0, 1, 0};//북동남서
int dy[] = {0, 1, 0, -1};
int n;
int sx, sy, ex, ey;
int answer = 100000;
void dijkstra()
{
    priority_queue<Data> pq;
    pq.push({sx, sy, 0, -1});
    dist[sx][sy] = 0;
    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int nowCost = pq.top().w;
        int d = pq.top().d;
        // cout << x << ' ' << y << ' ' << nowCost << ' ' << d<< "\n\n"; 
        pq.pop();
        if (x == ex && y == ey)
        {
            if (nowCost < answer)
                answer = nowCost;
            continue;
        }
        if (nowCost < dist[x][y])
        {
            // cout << "skip\n";
            continue;
        }
        for (int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextCost = dist[x][y];
            int nd = i;
            if (d != -1 && d != i)
                nextCost++;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || graph[nx][ny] == 'x')
                continue;
            if (nextCost < dist[nx][ny])
            {
                dist[nx][ny] = nextCost;
                pq.push({nx, ny, nextCost, nd});
            }
        }
    }
}
int main()
{    
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
            dist[i][j] = 2147483647;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A'){
                sx = i;
                sy = j;
            }
            if (graph[i][j] == 'B'){
                ex = i;
                ey = j;
            }
        }
    dijkstra();
    cout << answer;
    
}