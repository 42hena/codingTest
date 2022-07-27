#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct info
{
    long long start; long long end;
    int index;
    bool operator<(const info &c) const
    {
        if (start == c.start)
            return end > c.end;
        return start < c.start; 
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long m;
    cin >> m;
    
    vector<info> v;
    for (int i = 0 ; i < m ; ++i)
    {
        long long a, b;
        cin >> a >> b;
        
        if (a > b)
        {
            v.push_back({a - n , b, i + 1});
            v.push_back({a, b + n, i + 1});
        }
        else
            v.push_back({a, b, i + 1});
    }
    sort(v.begin(), v.end());


    set<int> ans;
    // vector<int> ans;
    ans.insert(v[0].index);
    int temp = 0;
    for (int i = 1 ; i < m ; ++i)
    {
        int nowIndex = v[i].index;
        if (v[temp].end < v[i].end)
        {
            ans.insert(nowIndex);
            temp = i;
        }
    }
    for (auto x : ans)
        cout << x << ' ';
}