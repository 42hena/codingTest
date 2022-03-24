#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

int n, m;
int paths[251][251];
int test[251][251];
const int INF = 1e9;
void initPaths()
{
	for (int i = 1 ; i < n + 1 ; ++i)
	{
		for (int j = 1 ; j < n + 1 ; ++j)
		{
			if (i == j)
			{
				paths[i][j] = 0;
				test[i][j] = 0;
			}
			else
			{
				paths[i][j] = INF;
				test[i][j] = INF;
			}
		}
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	initPaths();
	int u, v, b;
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> u >> v >> b;
		if (b == 1)
			paths[v][u] = 1;
		paths[u][v] = 1;
		test[v][u] = 1;
	}

	for (int k = 1 ; k < n + 1 ; ++k)
	{
		for (int i = 1 ; i < n + 1 ; ++i)
		{
			for (int j = 1 ; j < n + 1 ; ++j)
			{
				paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
			}
		}
	}
	for (int i =  1; i < n + 1 ; ++i)
	{
		for (int j = 1 ; j < n + 1 ; ++j)
		{
			if (paths[i][j] != INF)
				test[i][j] = 0;
		}
	}

	for (int k = 1 ; k < n + 1 ; ++k)
	{
		for (int i = 1 ; i < n + 1 ; ++i)
		{
			for (int j = 1 ; j < n + 1 ; ++j)
			{
				test[i][j] = min(test[i][j], test[i][k] + test[k][j]);
			}
		}
	}
	int k;
	cin >> k;
	int s, e;
	for (int i = 0 ; i < k ; ++i)
	{
		cin >> s >> e;
		cout << test[s][e] << '\n';
	}


}