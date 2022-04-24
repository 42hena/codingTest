#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
int parent[MAX];
int counted[MAX];
int ans[MAX];
vector<int> graph[MAX];
int main()
{
	int  n, m;

	cin >> n >> m;
	for (int i = 1 ; i < n + 1 ; ++i)
	{
		cin >> parent[i];
		if (parent[i] == -1)
			continue;
		graph[parent[i]].push_back(i);
	}
	int num, w;
	for (int i = 0  ; i < m ; ++i)
	{
		cin >> num >> w;
		counted[num] += w;
	}
	for (int i = 1 ; i < n + 1 ; ++i)
	{
		if (counted[i])
			ans[i] += counted[i];
		for (int j = 0 ; j < graph[i].size() ; ++j)
		{
			int next = graph[i][j];
			if (next != 0)
				ans[next] += ans[i];
		}
	}
	for (int i = 1 ; i < n + 1 ; ++i)
		cout << ans[i] << ' ';
}