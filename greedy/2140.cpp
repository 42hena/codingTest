#include <bits/stdc++.h>
using namespace std;
string tmp;
int board[100][100];
bool mine[100][100];
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx[] = {-1, 1, 0, 1, -1, 1, 0, -1};
int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> tmp;
        for (int j = 0 ; j < n ; ++j)
        {
            if (tmp[j] == '#')
                board[i][j] = -1;
            else
                board[i][j] = tmp[j] - '0';
        }
    }
    for (int i = 1 ; i < n - 1 ; ++i)
    {
        for (int j = 1 ; j < n - 1 ; ++j)
        {   
            int minValue = 10;
            for (int d = 0 ; d < 8 ; ++d)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue ;
                if (board[ny][nx] == -1)
                    continue;
                minValue = min(minValue, board[ny][nx]);
            }
            // cout << i << ' ' << j << ' ' << minValue << '\n';
            if (!minValue || minValue == 10)
                continue;
            for (int d = 0 ; d < 8 ; ++d)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue ;
                if (board[ny][nx] == -1)
                    continue;
                board[ny][nx] -= minValue;
            }   
            mine[i][j] = true;
        }
    }
    int cnt = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
        {
            if (mine[i][j])
                cnt++;
        }
    }
    if (n >= 4)
        cnt += (n - 4) * (n - 4);
    cout << cnt << '\n';
}