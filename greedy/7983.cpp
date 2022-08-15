#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    int playtime;
    int endtime;
    bool operator<(const Data &c) const
    {
        return  endtime > c.endtime;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<Data> v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i].playtime >> v[i].endtime;
    sort(v.begin(), v.end());

    int nowTime = v[0].endtime;
    for (int i = 0 ; i < n ; ++i)
    {
        if (nowTime > v[i].endtime)
            nowTime = v[i].endtime;
        nowTime -= v[i].playtime;
        // cout << nowTime << '\n';
    }
    cout << nowTime;
}