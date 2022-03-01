#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> people(n);
    long long right = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> people[i];
        right = max(right, people[i]);
    }
    
    long long left = 0;
    right = right * m;
    long long ans = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long sum = 0;
        
        for (int i = 0 ; i < people.size() ; ++i)
        {
            sum += mid / people[i];
        }
        if (sum >= m)
        {
            ans = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    cout << ans;
}