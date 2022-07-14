#include <iostream>
using namespace std;

string board[10000];
bool visited[10000][500];

int dy[] = {-1, 0, 1};
int dx[] = {1, 1, 1};

int r, c;
bool dfs(int y, int x)
{
    visited[y][x] = true;
    if (x == c - 1)
        return true;
    for (int i = 0 ; i < 3 ; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || visited[ny][nx] || board[ny][nx] == 'x')
            continue ;
        if (dfs(ny, nx))
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    string tmp;
    for (int i = 0 ; i < r ; ++i)
    {
        cin >> board[i];
    }
    
    int count = 0;
    for (int i = 0 ; i < r ; ++i)
    {
        if (dfs(i, 0))
        {
            count++;
        }
    }   
    cout << count;
}