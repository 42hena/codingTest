#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int distance;
    int fuel;
    bool operator<(const Data &c) const
    {
        return fuel < c.fuel;
    }
};

int main(void)
{
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    int l, p;
    cin >> l >> p;
    
    priority_queue<Data> pq;
    int cnt = 0;

    for (int i = 0 ; i < n ; ++i)
    {
        // cout << "index: " << i << " pqsize: " << pq.size() << " p: " << p <<'\n';
        if (p >= v[i].first)
        {
            pq.push({v[i].first, v[i].second});
        }
        else
        {
            if (pq.empty())
                break;
            // cout << pq.top().distance << ' ' << pq.top().fuel <<'\n';
            p += pq.top().fuel;
            pq.pop();
            cnt++;
            --i;
        }
        // cout << v[i].first << ' ' << v[i].second << '\n';
    }
    while (!pq.empty() && p < l)
    {
        p += pq.top().fuel;
        pq.pop();
        cnt++;
    }
    if (p >= l)
        cout << cnt;
    else
        cout << -1;
}