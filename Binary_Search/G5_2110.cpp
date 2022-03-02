#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> router(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> router[i];
    sort(router.begin(), router.end());
    int l = 0;
    int r = 1000000000;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int sum = 0;
        int cnt = 1;
        for (int i = 0 ; i < n - 1 ; ++i)
        {
            int value = router[i + 1] - router[i];
            sum += value;
            if (sum >= m)
            {
                sum = 0;
                cnt++;
            }
        }
        if (cnt >= c)
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    cout << ans;
}