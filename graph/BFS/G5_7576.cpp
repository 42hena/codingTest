#include <bits/stdc++.h>
using namespace std;
int graph[1000][1000];
int visit[1000][1000];
struct Data{
    int x, y;
};
vector<Data> pos;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int m, n;
int maxValue = 1;
void breadthFirstSearch()
{
    queue<Data> q;
    for (int i = 0 ; i < pos.size() ; ++i)
        q.push({pos[i].x, pos[i].y});
    while (!q.empty())
    {
        Data tmp = q.front();
        q.pop();

        for (int i = 0 ; i < 4 ; ++i)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] == -1 || graph[nx][ny])
                continue;
            q.push({nx, ny});
            graph[nx][ny] = graph[tmp.x][tmp.y] + 1;
            maxValue = max(maxValue, graph[nx][ny]);
        }
    }
    bool flag = true;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            if (graph[i][j] == 0)
                flag = false;
    maxValue = (flag ? maxValue - 1 : -1);
    cout << maxValue;  
}
int main()
{
    cin >> m >> n;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
                pos.push_back({i, j});
        }
    
    breadthFirstSearch();
}