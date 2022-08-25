#include <bits/stdc++.h>
using namespace std;

bool board[1000][1000];
int     add[1000][1000];
bool state[1000][1000];
void print()
{

}
int main()
{
    int n;  cin >> n;
    char ch;

    
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> ch;
        if (ch == '.')
            state[0][i] = board[0][i] = 0;
        else

            state[0][i] = board[0][i] = 1;
    }

    int dy[] = {0, 0};
    int dx[] = {1, -1};
    
    // 첫 행 세팅
    int i = 0;
    for (int j = 0 ; j < n ; ++j)
    {
        if (board[i][j])
        {
            state[i][j] = !state[i][j];
            add[i + 1][j]++;//주의
            for (int d = 0 ; d < 2 ; ++d)
            {
                int nx = j + dx[d];
                if (nx < 0 || nx >= n)
                    continue;
                state[i][nx] = !state[i][nx];
            }
        }
    }

    // for (int j = 0 ; j < n ; ++j)
    // {
    //     cout << state[0][j];
    // }
    // cout << '\n';
    //clear

    int dya[] = {0, 0, 0, 1};
    int dxa[] = {-1, 0, 1, 0};
    for (int i = 1 ; i < n ; ++i)
    {
        // board결정
        for (int j = 0 ; j < n ; ++j)
        {
            if (state[i - 1][j])
            {
                board[i][j] = 1;
                // state[i - 1][j] = !state[i - 1][j];
                for (int d = 0 ; d < 4 ; ++d)
                {
                    int ny = i + dya[d];
                    int nx = j + dxa[d];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                        continue;
                    add[ny][nx]++;
                }
            }
            // else
            //     board[i][j] = 0;
        }

        for (int j = 0 ; j < n ; ++j)
        {
            int cnt = add[i][j] % 2 ;
            state[i][j] = board[i][j];
            if (cnt)
            {
                state[i][j] = !state[i][j];
            }
        }
        // for (int j = 0 ; j < n ; ++j)
        //     cout << board[i][j] << ' ';
        // for (int j = 0 ; j < n ; ++j)
        //     cout << state[i][j] << ' ';
        // for (int j = 0 ; j < n ; ++j)
        //     cout << add[i][j] << ' ';
        // cout << '\n';
    }

    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
        {
            if (board[i][j])
                cout << '#';
            else
                cout << '.';
        }
        cout << '\n';
    }
}