#include <bits/stdc++.h>
using namespace std;
char graph[100][100];
int dist[100][100];

struct Data{
    int x, y, w, dw,  d;
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
    pq.push({sx, sy, 0, 0, -1});
    dist[sx][sy] = 0;
    
    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int nowCost = pq.top().w;
        int dw = pq.top().dw; 
        int d = pq.top().d; 
        pq.pop();
        // cout << x << ' ' << y << ' ' << nowCost << ' ' << dw << ' ' << d << '\n'; 
        if (x == ex && y == ey)
        {
            if (dw < answer)
                answer = dw;
            continue;
        }
        
        for (int i = 0 ; i < 4 ; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nextCost = dist[x][y] + 1;
            int nextdw = dw;
            int nd = i;
            
            if (d != -1 && (!((d + 2) % 4 == i || d == i)))
                nextdw++;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || graph[nx][ny] == 'x')
                continue;
            if (nextCost <= dist[nx][ny])
            {
                dist[nx][ny] = nextCost;
                pq.push({nx, ny, nextCost, nextdw,  nd});
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