#include <iostream>
#include <vector>
using namespace std;

#define MAX 101
#define INF 1e9
int cost[MAX][MAX];

int n, m;
void initCost()
{
	for (int i = 1 ; i < n + 1 ; ++i)
	{
		for (int j = 1 ; j < n + 1 ; ++j)
		{
			cost[i][j] = INF;
			if (i == j)
				cost[i][j] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;

	int v1, v2;

	initCost();
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> v1 >> v2;
		cost[v1][v2] = 1;
		cost[v2][v1] = 1;
	}
	for (int k = 1 ; k < n + 1 ; ++k)
		for (int i = 1 ; i < n + 1 ; ++i)
			for (int j = 1 ; j < n + 1 ; ++j)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

	int minValue = INF;
	vector<int> v;
	for (int i = 1 ; i < n + 1 ; ++i)
	{
		int sum = 0;
		for (int j = 1 ; j < n + 1 ; ++j)
			sum += cost[i][j];
		if (minValue > sum)
		{
			minValue = sum;
			v.clear();
			v.push_back(i);
		}
		else if (minValue  == sum)
			v.push_back(i);
	}
	cout << v[0];
}