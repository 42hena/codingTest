#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for (int i = 0  ; i < n ; ++i)
    {
        int value;
        cin >> value;
        pq.push(value);
    }
    int now = 1;
    long long ans = 0;
    while (!pq.empty())
    {   
        int pqValue = pq.top();pq.pop();
        if (now <= pqValue)
        {
            ans += pqValue - now;
            now++;
        }
    }
    cout << ans;
}