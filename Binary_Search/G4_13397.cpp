#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    int l = 0;
    int r = 10000;
    int answer = 0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int cnt = 1;
        int maxValue = v[0];
        int minValue = v[0];
        // cout << mid << '\n';
        for (int i = 0 ; i < n ; ++i)
        {
            maxValue = max(maxValue, v[i]);
            minValue = min(minValue, v[i]);
            if (maxValue - minValue > mid)
            {
                maxValue = minValue = v[i];
                cnt++;
            }
        }
        if (cnt > m)
            l = mid + 1;   
        else
        {
            answer = mid;
            r = mid - 1;
        }
    }
    cout << answer;
}