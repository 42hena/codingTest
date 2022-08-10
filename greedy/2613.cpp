#include <bits/stdc++.h>
using namespace std;

int n, m;

bool ParametricSearch(int m, vector<int> &ans, const vector<int> &v)
{
    int sum = 0;
    int locSize = 1;
    for (int i = 0 ; i < n ; ++i)
    {
        sum += v[i];
        if (sum > mid)
        {
            locSize++;
            sum = v[i];
        }
    }
    return cnt;
}

int main(void)
{
    cin >> n >> m;
    vector<int> v(n);
    int total = 0;
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];

    int left = 0;
    int right = 30000;
    int maxValue = 0;
    vector<int> ans;
    int value = 0;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = getCnt(mid);
        if (cnt >m)
            l = mid + 1;
        else
        {
            r = mid - 1;
            if (mid < ans) ans = mid;
        }
    }
    cout << l << '\n';
    cout << maxValue << '\n';
    for (auto x : ans)
        cout << x << ' ';   
}