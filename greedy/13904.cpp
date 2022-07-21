#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int d, w;
    bool operator<(const Data &copy)
    {
        if (d == copy.d)
            return w > copy.w;
        return d > copy.d;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Data> v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i].d >> v[i].w;
    }
    sort(v.begin(), v.end());
    int now = v[0].d;
    int ans = 0;
    for (int now = v[0].d ; now >= 1 ; --now)
    {
        int maxValue = 0;
        int maxIndex = -1;
        
        for (int i = 0 ; i < v.size() ; ++i)
        {
            if (now <= v[i].d)
            {
                if (maxValue < v[i].w)
                {
                    maxValue = v[i].w;
                    maxIndex = i;
                }
            }
            else
                break;
        }
        // for (auto value : v)
        // {
        //     cout << value.d << ' ' << value.w <<'\n';
        // }
        // cout << '\n';
        ans += maxValue;
        // cout << "ans: " << ans << '\n';
        if (maxIndex != -1)
            v.erase(v.begin() + maxIndex);
    }
    cout << ans;
}