#include <bits/stdc++.h>
using namespace std;

int dp[1000][3];
int house[1000][3];
int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < 3 ; ++j)
            cin >> house[i][j];
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < 3 ; ++j)
            dp[i][j] = 1e9;
    }
    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];
    int dx[] = {-1, 0, 1};

    for (int i = 1 ; i < n ; ++i)
    {
        for (int j = 0 ; j < 3 ; ++j)
        {
            for (int d = 0 ; d < 3 ; ++d)
            {
                int ny = i - 1;
                int nx = d;
                if (nx == j)
                    continue;
                dp[i][j] = min(dp[ny][nx] + house[i][j],dp[i][j] );
            }
            
        }
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
}