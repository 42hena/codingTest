#include <bits/stdc++.h>

using namespace std;
#define MAX (int)1e5 + 1;
char board[5][5];
bool visited[5][5];
int maxValue = -2147483648;
int minValue = 2147483647;
int dy[] = {1, 0};
int dx[] = {0, 1};
int n;
void DFS(int y, int x, vector<char> & v)
{
    if (y == n - 1 && x == n -1)
    {
        int sum = 0;
        for (int i = 0 ; i < v.size() ; i = i + 2)
        {
            if (i == 0)
                sum = v[i] - '0';
            else
            {
                int tmp;
                if (v[i] >= '0' && v[i] <= '9')
                    tmp = v[i] - '0';
                if (v[i - 1] == '+')
                    sum += tmp;
                else if (v[i - 1] == '-')
                    sum -= tmp;
                else if (v[i - 1] == '*')
                    sum *= tmp;
            }
        }
        minValue = min(minValue, sum);
        maxValue = max(maxValue, sum);
        visited[y][x] = false;
        return ;
    }

    for (int i = 0 ; i < 2 ; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx])                        continue;
        visited[ny][nx] = true;
        v.push_back(board[ny][nx]);
        DFS(ny, nx, v);
        v.pop_back();
        visited[ny][nx] = false;
    }
}

int main()
{
    
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
            cin >> board[i][j];
    vector<char> v;
    v.push_back(board[0][0]);
    visited[0][0] = true;
    DFS(0, 0, v);
    cout << maxValue << ' ' << minValue;
}