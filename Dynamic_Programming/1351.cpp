#include <bits/stdc++.h>
using namespace std;

map<long long, long long> dp;
long long n, p, q;
long long recursive(long long n)
{
    if (dp.count(n))
        return dp[n];
    return dp[n] = (recursive(n / p) + recursive(n / q));
}
int main()
{
        
    cin >> n >> p >> q;
    dp[0] = 1;
    cout << recursive(n) << '\n';
}