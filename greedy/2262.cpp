#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n==1)
    {
        cout << 0;
        return 0;
    }
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    n++;
    int total = 0;
    while (--n > 1)
    {
        // cout << n << '\n';
        int i;
        // cout << "TEST\n";
        // for (i = 0 ; i < n ; ++i)
        //     cout << v[i] << ' ';
        // cout << '\n';
        // cout << "TEST\n\n";
        for (i = 0 ; i < n ; ++i)
        {
            if (v[i] == n)
                break;
        }
        int left = 1e9, right = 1e9;
        // cout << "index" << i << '\n';
        if (i > 0)
            left = abs(v[i] - v[i - 1]);
        if (i < n - 1)
            right = abs(v[i] - v[i + 1]);
        total += min(left, right);
        // cout << "total:" << total << '\n';
        v.erase(v.begin() + i);
    }
    cout << total;
}