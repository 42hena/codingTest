#include <bits/stdc++.h>
using namespace std;
int Data[500001];
int main()
{
    int n, h, value;
    cin >> n >> h;
    vector<int> down;
    vector<int> up;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> value;
        if (i % 2 == 0)
            down.push_back(value);
        else
            up.push_back(h - value);
    }
    sort(down.begin(), down.end());
    sort(up.begin(), up.end());
    int minValue = 500001;
    for (int i = 1 ; i <= h ; ++i)
    {
        Data[i] = down.end() - lower_bound(down.begin(), down.end(), i) + lower_bound(up.begin(), up.end(), i) - up.begin();
        if (minValue > Data[i])
            minValue = Data[i];
    }
    int count = 0;
    for (int i = 1 ; i <= h ; ++i)
    {
        if (minValue == Data[i])
            count++;
    }
    cout << minValue << ' ' << count;
}