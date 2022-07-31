#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i];
    }
    int maxValue = v[n - 1] - v[0];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0 ; i < n - 1 ; ++i)
        pq.push(v[i + 1] - v[i]);
    int cnt = n - k;
    int total = 0;
    while (pq.size() && cnt--)
    {
        total += pq.top();
        pq.pop();
    }
    cout << total;
}