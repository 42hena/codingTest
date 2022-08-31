#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    dp[3] = 22;
    long long tmp = 0;
    for (int i = 3 ; i < 1000001 ; ++i) {
        tmp += dp[i - 3] * 2;
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3 + tmp) % 1000000007LL;
    }
    cout << dp[n];
}