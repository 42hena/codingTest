#include <bits/stdc++.h>
using namespace std;
int cache[5001];
int main()
{
    int n;
    fill (cache, cache + 5001, 100000);
    cin >> n;
    cache[0] = 0;
    for (int i = 3 ; i <= n ; ++i)
    {
        // if (i >= 5 && cache[i - 3] != -1 && cache[i - 5] != -1)
        //     cache[i] = min(cache[i - 5], cache[i - 3]) + 1;
        if (i >= 3)
            cache[i] = min(cache[i - 3] + 1, cache[i]);
        if (i >= 5)
            cache[i] = min(cache[i - 5] + 1, cache[i]);
    }
    if (cache[n] == 100000)
        cout << -1;
    else
        cout << cache[n];
}