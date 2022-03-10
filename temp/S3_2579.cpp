//https://www.acmicpc.net/problem/2579
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
void fastIO()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
int arr[10000];
int dp[10000];
int main(void)
{
    
    int n;
    cin >> n;

    for (int i = 0 ; i < n ; ++i)
        cin >> arr[i];
    dp[0] = arr[0];
    dp[1] = arr[1] + dp[0];
    dp[2] = arr[2] + max(arr[0], arr[1]);
    for (int i = 3 ; i < n ; ++i)
    {
        dp[i] = arr[i] + max(arr[i - 1] + dp[i - 3], dp[i - 2]);
    }
    cout << dp[n - 1] << ' ';
}