#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
int cost1[100][100];
int cost2[100][100];
int main()
{
	int n, m;
	cin >> n >> m;
	int v1, v2;

	for (int i = 0 ; i < n + 1 ; ++i)
	{
		for (int j = 0 ; j < n + 1 ; ++j)
		{
			cost1[i][j] = cost2[i][j] = INF;
		}
	}

	for (int i = 0 ; i < n + 1 ; ++i)
	{
		cost1[i][i] = cost2[i][i] = 0;
	}
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> v1 >> v2;
		cost1[v1][v2] = 1;
		cost2[v2][v1] = 1;
	}

	for (int k = 1 ; k < n + 1 ; ++k)
	{
		for (int i = 1 ; i < n + 1 ; ++i)
		{
			for (int j = 1 ; j < n + 1 ; ++j)
			{
				cost1[i][j] = min(cost1[i][k] + cost1[k][j], cost1[i][j]);
				cost2[i][j] = min(cost2[i][k] + cost2[k][j], cost2[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1 ; i < n + 1 ; ++i)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		for (int j = 1 ; j < n + 1 ; ++j)
		{
			if (cost1[i][j] > 0 && cost1[i][j] < INF)
				cnt1++;
			if (cost2[i][j] > 0 && cost2[i][j] < INF)
				cnt2++;
		}
		if (cnt1 >= n / 2 + 1 || cnt2 >= n / 2 + 1)
			ans++;
	}
	cout << ans;
}