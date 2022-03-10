#include <bits/stdc++.h>
using namespace std;
char board[10][10];
bool visited[10][10][10][10];
struct Data
{
    int rx, ry, bx, by, count;
};
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<Data> q;
int ret = -1;
int BFS()
{
    
    while (!q.empty())
    {
        Data now = q.front();
        q.pop();
        if (now.count > 10) break;
        if (board[now.rx][now.ry] == 'O' && board[now.bx][now.by] != 'O')
        {
            
            ret = now.count;
            // cout << "value" << ret << '\n';
            break;
        }
        for (int i = 0 ; i < 4 ; ++i)
        {
            int nrx = now.rx;
            int nry = now.ry;
            int nbx = now.bx;
            int nby = now.by;
            while (true)
            {
                if (board[nrx][nry] != '#' && board[nrx][nry] != 'O')
                {
                    nrx += dx[i], nry += dy[i];
                }
                else
                {if (board[nrx][nry] == '#') 
                {
                    nrx -= dx[i], nry -= dy[i];
                    
                }
                break;
                }
            }

            while (true)
            {
                if (board[nbx][nby] != '#' && board[nbx][nby] != 'O')
                {
                    nbx += dx[i], nby += dy[i];
                }
                else
                {
                    if (board[nbx][nby] == '#') 
                    {
                        nbx -= dx[i], nby -= dy[i];
                        
                    }
                    break;
                }
            }

            if(nrx==nbx && nry==nby){
                if(board[nrx][nry]!='O'){ 
                    int red_dist = abs(nry - now.ry)+abs(nrx-now.rx);
                    int blue_dist = abs(nby - now.by)+abs(nbx-now.bx);
                    if(red_dist>blue_dist){
                            nry-=dy[i];
                            nrx-=dx[i];
                    }
                    else{
                            nby-=dy[i];
                            nbx-=dx[i];
                    }
                }
            }
            if(visited[nrx][nry][nbx][nby]==0){
                visited[nrx][nry][nbx][nby]=1;
                int ncount = now.count+1;
                q.push({nrx, nry, nbx, nby, ncount});
            }
        }
    }
    return ret;
}
 
int main()
{

    cin >> n >> m;
    int rx, ry, bx, by;
    for (int i = 0 ; i < n ; ++i)
    {
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
    }
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;
    
    cout << BFS();
}