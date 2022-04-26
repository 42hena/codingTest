#include <iostream>

using namespace std;
#define MAX 250
char board[MAX][MAX];
bool visited[MAX][MAX];

int wolfCount;
int sheepCount;
int wolfTmpCount;
int sheepTmpCount;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int r, c;
void DFS(int y, int x)
{
    visited[y][x] = true;

    if (board[y][x] == 'o')
        sheepTmpCount+=1;
    if (board[y][x] == 'v')
        wolfTmpCount += 1;
    for (int i = 0 ; i < 4 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;
        if (board[ny][nx] == '#')
            continue;
        if (!visited[ny][nx])
            DFS(ny, nx);
    }
}
int main()
{
    cin >> r >> c;

    for (int i = 0 ; i < r ; ++i)
    {
        for (int j = 0 ; j < c ; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0 ; i < r ; ++i)
    {
        for (int j = 0 ; j < c ; ++j)
        {
            if (!visited[i][j] && board[i][j] != '#')
            {
                wolfTmpCount = 0;
                sheepTmpCount = 0;
                DFS(i, j);
                if (wolfTmpCount < sheepTmpCount)
                    sheepCount += sheepTmpCount;
                else
                    wolfCount += wolfTmpCount;
            }
        }
    }
    cout << sheepCount <<  ' ' << wolfCount;
}