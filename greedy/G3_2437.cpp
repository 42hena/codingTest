#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 1;
    for (auto value : v)
    {
        if (ans < value)
            break;
        ans += value;
    }
    cout << ans;

}