#include <bits/stdc++.h>
using namespace std;
int n;

char Map[100][100];
bool visited[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void normal(int x, int y, char c)
{
    visited[x][y] = true;

    for (int i = 0 ; i < 4 ; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue ;
        if (Map[nx][ny] != c || visited[nx][ny])
            continue ;
        normal(nx, ny, c);
    }
}

void red_green(int x, int y, char c)
{
    visited[x][y] = true;
    for (int i = 0 ; i < 4 ; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue ;
        if (visited[nx][ny])
            continue ;
        if ((c == 'R' || c == 'G') && (Map[nx][ny] == 'R' || Map[nx][ny] == 'G'))
            red_green(nx, ny, c);
        else if ((c == 'B') && (Map[nx][ny] == 'B'))
            red_green(nx, ny, c);

    }
}

int main()
{
    cin >> n;
    string tmp;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> tmp;
        for (int j = 0 ; j < n ; ++j)
            Map[i][j] = tmp[j];
    }

    int normalCnt = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
            if (!visited[i][j]){
                normal(i, j, Map[i][j]);
                normalCnt++;
            }
    }

    memset(visited, false, sizeof(visited));

    int handCnt = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
            if (!visited[i][j]){
                red_green(i, j, Map[i][j]);
                handCnt++;
            }
    }
    cout << normalCnt << ' ' << handCnt << '\n';   
}