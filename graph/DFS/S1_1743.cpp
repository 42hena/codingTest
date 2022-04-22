#include <bits/stdc++.h>
using namespace std;
char board[100][100];
bool visited[100][100];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n, m, k;
int DFS(int y, int x)
{
    // cout << y << ' ' << x << '\n';
    int count = 0;
    visited[y][x] = true;
    for (int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (!visited[ny][nx] && board[ny][nx] == '#')
            count += DFS(ny, nx);
    }
    return count + 1;
}
int main()
{
    cin >> n >> m >> k;
    int y, x;
    
    for (int i = 0 ; i < k ; ++i)   
    {
        cin >> y >> x;
        board[y - 1][x - 1] = '#';
    }

    int maxValue = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < m ; ++j)
            if (!visited[i][j] && board[i][j] == '#')
            {
                maxValue = max(DFS(i, j), maxValue);
            }
    }
    cout << maxValue;
}