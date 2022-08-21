#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    LL total = 0;    
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i].first >> v[i].second;
        total += v[i].second;
    }
    sort(v.begin(), v.end());
    if (total & 1)
    {
        total = (total >> 1) + 1;
    }
    else {
        total >>= 1;
    }
    for (int i = 0 ; i < n ; ++i)
    {
        if (total - v[i].second <= 0)
        {
            cout << v[i].first << '\n';
            break;
        }
        total -= v[i].second;
    }
}