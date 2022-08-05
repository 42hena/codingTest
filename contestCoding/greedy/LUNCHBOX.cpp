#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i].first;
        for (int i = 0; i < n; ++i)
            cin >> v[i].second;
        sort(v.begin(), v.end(), compare);
        // for (auto x : v)
        //     cout << x.first << ' ' << x.second << '\n';
        int time = 0;
        int maxValue = 0;
        for (auto x : v)
        {
            time += x.first;
            if (maxValue < time + x.second)
            {
                maxValue = time + x.second;
            }
        }
        cout << maxValue << '\n';
    }
}