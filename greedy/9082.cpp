#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string board[2];
        for (int i = 0; i < 2; ++i)
            cin >> board[i];

        // for (int i = 0; i < n ; ++i)
        // {
        //     if (board[1][i] == '*')
        //     {
        //         int ny = 0;
        //         for (int d = 0 ; d < 3 ; ++d)
        //         {
        //             int nx = i + dx[d];
        //             if (nx < 0 || nx >= n)
        //                 continue;
        //             if (board[ny][nx] != '0')
        //                 board[ny][nx] -= 1;
        //         }
        //     }
        // }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            bool flag = true;
            if (board[1][i] == '*' || board[1][i] == '#')
            {
                for (int d = 0; d < 3; ++d)
                {
                    int nx = i + dx[d];
                    if (nx < 0 || nx >= n)
                        continue;
                    if (board[0][nx] == '0')
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    continue;
                for (int d = 0; d < 3; ++d)
                {
                    int nx = i + dx[d];
                    if (nx < 0 || nx >= n)
                        continue;
                    board[0][nx] -= 1;
                }
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}