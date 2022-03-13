#include <bits/stdc++.h>
using namespace std;
//피사노 주기를 알아야함
int main()
{
    long long n;
    int dp[1500000] = {0};
    cin >> n;
    dp[1] = 1;
    for (int i = 2 ; i < 1500000 ; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
    }
    cout << dp[n % 1500000];
}