#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0 ; i < n ; ++i)
    {
        if (pq.empty())
        {
            pq.push(v[i].second);
        }
        else
        {
            int start = pq.top();
            if (start <= v[i].first)
                pq.pop();
            pq.push(v[i].second);
        }
    }
    cout << pq.size();
}