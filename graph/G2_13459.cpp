#include <bits/stdc++.h>
using namespace std;
char board[10][10];
bool visited[10][10][10][10];
int rx, ry, bx, by;
int n, m;
struct marble{
    int rx, ry, bx, by, moveCount;
};
queue<marble> marbleQueue;
//marble이 구슬이라네?
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool BFS()
{
    int ret = 0;
    marbleQueue.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;
    while (!marbleQueue.empty())
    {
        marble now = marbleQueue.front();
        marbleQueue.pop();
        if (now.moveCount > 10)
            break;
        if (board[now.rx][now.ry] == 'O' && board[now.bx][now.by] != 'O')
        {
            ret = 1;
            break;
        }
        for (int direction = 0 ; direction < 4 ; ++direction)
        {
            int nrx = now.rx, nry = now.ry, nbx = now.bx, nby = now.by;
            while (true)
            {
                if (board[nrx][nry] != '#' && board[nrx][nry] != 'O')
                {
                    nrx += dx[direction];
                    nry += dy[direction];
                }
                else
                {
                    if (board[nrx][nry] == '#')
                    {
                        nrx -= dx[direction];
                        nry -= dy[direction];
                    }
                    break;   
                }
            }
            
            while (true)
            {
                if (board[nbx][nby] != '#' && board[nbx][nby] != 'O')
                {
                    nbx += dx[direction];
                    nby += dy[direction];
                }
                else
                {
                    if (board[nbx][nby] == '#')
                    {
                        nbx -= dx[direction];
                        nby -= dy[direction];
                    }
                    break;   
                }
            }
            //같을 경우 판별 해야함
            if (nrx == nbx && nry == nby)
            {
                if (board[nrx][nry] != 'O'){
                    int red_distance = abs(now.rx - nrx) + abs(now.ry - nry);
                    int blue_distance = abs(now.bx - nbx) + abs(now.by - nby);
                    if (red_distance > blue_distance)
                    {
                        nrx -= dx[direction];
                        nry -= dy[direction];   
                    }
                    else
                    {
                        nbx -= dx[direction];
                        nby -= dy[direction];   
                    }
                }
            }
            if (!visited[nrx][nry][nbx][nby])
            {
                visited[nrx][nry][nbx][nby] = true;
                marbleQueue.push({nrx, nry, nbx, nby, now.moveCount + 1});
            }
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            if (board[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    cout << BFS();
}