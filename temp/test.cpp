#include <bits/stdc++.h>
using namespace std;
char graph[20][20];
// bool visited[20][20];
bool visited[26];
set<char> s;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c;
int maxValue;
void recursive(int x, int y, int cnt)
{
    // cout << graph[x][y] << '\n';
    if (cnt > maxValue)
        maxValue = cnt;
    for (int i = 0 ; i < 4 ; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;   
        // cout << nx << ny << '\n';
        // iter = s.find(graph[nx][ny]);
        
        // if (iter == s.end())
        // {
        if (!visited[graph[nx][ny] - 'A'])
        {
            visited[graph[nx][ny] - 'A'] = true;
            // s.insert(graph[nx][ny]);
            recursive(nx, ny, cnt + 1);
            visited[graph[nx][ny] - 'A'] = false;
            // s.erase(graph[nx][ny]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0 ; i < r ; ++i)
        for(int j = 0 ; j < c ; ++j)
            cin >> graph[i][j];
    visited[graph[0][0] - 'A'] = true;
    // s.insert(graph[0][0]);
    recursive(0, 0, 1);
    cout << maxValue;
}