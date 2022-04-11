#include <bits/stdc++.h>
using namespace std;

int cache[21][10001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; ++i)
            cin >> coins[i];
        int m;
        cin >> m;
        memset(cache, 0, sizeof(cache));
        for (int i = 1; i < n + 1; ++i)
        {
            int nowCoin = coins[i - 1];
            cache[i][0] = 1;
            for (int j = 1; j < m + 1; ++j)
            {
                if (j >= nowCoin)
                    cache[i][j] = cache[i - 1][j] + cache[i][j - nowCoin];
                else
                    cache[i][j] = cache[i - 1][j];
            }
        }
        cout << cache[n][m] << '\n';
    }
}