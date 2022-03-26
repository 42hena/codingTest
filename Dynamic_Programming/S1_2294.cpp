#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[10001];
int main()
{
	cin >> n >> k;
    for (int i = 0 ; i <= k ; ++i)
        dp[i] = 1e9;
	dp[0] = 0;
	vector<int> coins(n);
	for (int i = 0 ; i < n ; ++i)
		cin >> coins[i];
	for (int i = 0 ; i <= k ; ++i)
	{
		for (int j = 0 ; j < n ; ++j)
		{
			if (i - coins[j] >= 0)
				dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
		}
	}
	if (dp[k] == 1e9)
		cout << -1;
	else
		cout << dp[k];
}