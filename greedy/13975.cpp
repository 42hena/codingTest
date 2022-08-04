#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long total = 0;
        int n;
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int num;
        for (int i = 0 ; i < n ; ++i)
        {
            cin >> num;
            pq.push(num);
        }
        while (pq.size() > 1)
        {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();
            total += first + second;
            pq.push(first + second);
        }
        cout << total << '\n';
    }
}