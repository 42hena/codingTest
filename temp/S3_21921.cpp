#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n + 1);
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> v[i];
        v[i] += v[i-1];
    }
    int maxValue = 0;
    for (int i = 0  ; i <= n - x ; ++i)
        maxValue = max(maxValue, v[i + x] - v[i]);
    int cnt = 0;
    for (int i = 0  ; i <= n - x ; ++i)
        if (maxValue == v[i + x] - v[i])
            cnt++;
    if (maxValue == 0)
        cout << "SAD"<<'\n';
    else
        cout << maxValue << '\n' << cnt;
}