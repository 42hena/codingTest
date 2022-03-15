#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char board[100][100];
int dist[100][100][4];
int w, h;
int cx, cy;
#define INF 1000000009
vector<pair<int, int>> c;
void Input()
{
    cin >> w >> h;
    for (int i = 0 ; i < h ; ++i)
        for (int j = 0 ; j < w ; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'C')
                c.push_back({i, j});
            for (int k = 0 ; k < 4 ; ++k)
                dist[i][j][k] = INF;
        }
}
struct Data
{
    int x, y, count, direction;
    bool operator< (const Data &copy) const
    {
        return count > copy.count;
    }
};

void dijkstra()
{
    
    priority_queue<Data> pq;
    int x = c[0].first;
    int y = c[0].second;
    for (int i = 0 ; i < 4 ; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] == '*')
            continue;
        pq.push({x, y, 0, i});
        dist[x][y][i] = 0;
    }
    
    while (!pq.empty())
    {
        // Data now = pq.top();
        int x = pq.top().x;
        int y = pq.top().y;
        int count = pq.top().count;
        int dir = pq.top().direction;
        pq.pop();
        
        // cout << x << ' ' << y << ' ' << count << ' ' << dir << '\n';
        if (x == c[1].first && y == c[1].second)
        {
            cout << count << '\n';
            break;
        }
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= h || ny < 0 || ny >= w || board[nx][ny] == '*')
            continue;
        if (board[nx][ny] == '.')
        {
            int nd = dir - 1;
            if (nd < 0)
                nd = 3;
            if(dist[nx][ny][nd] > dist[x][y][dir] + 1)
            {
                dist[nx][ny][nd] = dist[x][y][dir] + 1;
                pq.push({nx, ny, count + 1, nd});
            }
            nd = (dir + 1) % 4;
            if(dist[nx][ny][nd] > dist[x][y][dir] + 1)
            {
                dist[nx][ny][nd] = dist[x][y][dir] + 1;
                pq.push({nx, ny, count + 1, nd});
            }
        }
        if(dist[nx][ny][dir] > dist[x][y][dir]){
            dist[nx][ny][dir] = dist[x][y][dir];
            pq.push({nx, ny, count, dir});
        }

    }
}

int main()
{
    Input();
    dijkstra();
}