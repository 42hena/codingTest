#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    int total = 0;
    int ans = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        total += v[i];
        ans += total;
    }
    cout << ans;
}