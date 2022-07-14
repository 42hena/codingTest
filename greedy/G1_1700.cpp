#include <bits/stdc++.h>
using namespace std;

// [n : 멀티탭 구멍의 개수]
// [k : 전기 용품의 총 사용횟수]
int n, k;
int main(void)
{
    cin >> n >> k;
    vector<int> schedule(k);
    for (int i = 0 ; i < k ; ++i)
    {
        cin >> schedule[i];
    }

    set<int> multitap;
    int ans = 0;
    for (int i = 0 ; i < k ; ++i)
    {
        if (multitap.size() < n)
        {
            multitap.insert(schedule[i]);
        }
        else
        {
            if (multitap.find(schedule[i]) != multitap.end())
                continue ;
            vector<pair<int, int>> v;
            for (auto value : multitap)
            {
                int maxValue = 101;
                for (int j = i + 1 ; j < k ; ++j)
                {
                    if (value == schedule[j])
                    {
                        maxValue = j-i;
                        break ;
                    }
                }
                v.push_back({maxValue, value});
            }
            sort(v.begin(), v.end(), greater<>());
            int delValue = v[0].second;
            multitap.erase(delValue);
            multitap.insert(schedule[i]);
            ans++;
        }
    }
    cout << ans;
}