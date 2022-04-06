#include <bits/stdc++.h>
using namespace std;

int cache[101][10];
#define INF (int)1e9
int recursive(int n, int now)
{
    if (n == 1)
        return cache[n][now];
    int &ret = cache[n][now];
    if (ret != -1)
        return ret;
    if (now == 0)
        ret = recursive(n - 1, now + 1);
    else if (now == 9)
        ret = recursive(n - 1, now - 1);
    else
        ret = (recursive(n - 1, now - 1) + recursive(n - 1, now + 1)) % INF;
    return ret;
}
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0 ; i <= 9 ; ++i)
        cache[1][i] = 1;
    for (int i = 1 ; i <= 9 ; ++i)
        sum = (sum + recursive(n, i)) % INF;
    cout << sum;
}