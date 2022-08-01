#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        int num;
        cin >> num;
        v[num - 1] = i;
    }
    int cnt = 1;
    int maxValue = 0;
    for (int i = 0 ; i < n - 1 ; ++i)
    {
        if (v[i] < v[i + 1])
        {
            cnt++;
            maxValue = max(cnt, maxValue);
        }
        else
            cnt = 1;
    }
    cout << n - maxValue;
}