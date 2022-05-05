#include <bits/stdc++.h>
using namespace std;
int n, m;
int sx, sy, ex, ey;
#define MAX 2001
char board[MAX][MAX];
char board2[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int minValue = 1e9;
vector<pair<int, int>> v;
void dfs(int y, int x, int cnt)
{
    // cout << y << ' ' << x << '\n';
    v.push_back({y, x});
    visited[y][x] = true;
    if (ey == y && ex == x)
    {
        if (minValue > v.size())
        {
            minValue = v.size();
            for (int i = 0 ; i < n ; ++i)
            {
                for (int j = 0 ; j < m ; ++j)
                {
                    if (board[i][j] == '+')
                        board2[i][j] = '+';
                    else{
                        if (!visited[i][j])
                        {
                            board2[i][j] = '@';
                        }
                        else
                            board2[i][j] = '.';
                    }
                }
            }
        }
        visited[y][x] = false;
        return ;
    }
    for (int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (board[ny][nx] == '+' || visited[ny][nx])                   continue;
        dfs(ny, nx, cnt + 1);
    }
    visited[y][x] = false;
    v.pop_back();
}

int main()
{
    cin >> n >> m;
    bool flag = false;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < m ; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == '.' && !flag && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
            {
                sy = i;
                sx = j;
                flag = true;
            }
            else if (board[i][j] == '.' && flag && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
            {
                ey = i;
                ex = j;
            }
        }
    }
    
    dfs(sy, sx, 0);

    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < m ; ++j)
        {
            cout << board2[i][j];
        }
        cout << '\n';
    }
}