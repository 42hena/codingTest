#include <bits/stdc++.h>
using namespace std;
int cache[5001];
int recursive(int n)
{
    if (n < 0)
        return 100000;
    if (cache[n] != -1)
        return cache[n];
    if (n == 0)
        return 0;
    
    int l = recursive(n - 5) + 1;
    int r = recursive(n - 3) + 1;
    // cout << l << ' ' << r << '\n';
    cache[n] = min(l, r);
    // cout << cache[n] << '\n';
    return cache[n];
}

int main()
{
    int n;
    int ret;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    ret = recursive(n);
    if (ret >=100000)
        cout << -1;
    else
        cout << cache[n];
}