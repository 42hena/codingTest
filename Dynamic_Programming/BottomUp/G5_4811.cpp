#include <bits/stdc++.h>
using namespace std;

long long cache[31][61];
int main()
{
    cache[1][1] = 1;
    cache[1][2] = 1;
    for (int i = 2 ; i < 30 + 1 ; ++i)
    {
        for (int j = 1 ; j < 2 * i + 1 ; ++j)
        {
            cache[i][j] = cache[i][j - 1] + cache[i - 1][j - 1];
        }
    }
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        cout << cache[n][2*n] << '\n';
    }
}