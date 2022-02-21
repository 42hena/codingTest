#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int n, m;
int p1, p2;
struct Data
{
	int v;
	int w;
	bool operator<(const struct Data &copy) const
	{
		return w > copy.w;
	}
};

vector<Data> graph1[801];
vector<Data> graph2[801];
int			dist1[801];
int			dist2[801];

void dijkstra(vector<Data> graph[], int dist[], int start)
{
	dist[start] = 0;
	priority_queue<Data> pq;

	pq.push({start, 0});

	while (!pq.empty())
	{
		int now = pq.top().v;
		int nowCost = pq.top().w;
		pq.pop();
		if (dist[now] < nowCost)
			continue;
		for (int i = 0 ; i < graph[now].size() ; ++i)
		{
			int next = graph[now][i].v;
			int nextCost = graph[now][i].w + dist[now];
			if (nextCost < dist[next])
			{
				dist[next] = nextCost;
				pq.push({next, nextCost});
			}
		}
	}

}
int main()
{
	cin >> n >> m;
	for (int i = 1 ; i <= n ; ++i)
	{
		dist1[i] = 8000001;
		dist2[i] = 8000001;
	}
	int v1, v2, w;
	for (int i = 0 ; i < m ; ++i)
	{
		cin >> v1 >> v2 >> w;
		graph1[v1].push_back({v2, w});
		graph1[v2].push_back({v1, w});
		graph2[v1].push_back({v2, w});
		graph2[v2].push_back({v1, w});
	}
	cin >> p1 >> p2;
	dijkstra(graph1, dist1, p1);
	dijkstra(graph2, dist2, p2);
	int a = dist1[1] + dist2[n] + dist1[p2];
	int b = dist1[n] + dist2[1] + dist2[p1];
	if (a < b)
	{
		if (a >8000000)
			cout << -1;
		else
			cout << a;
	}
	else
	{
		if (b > 8000000)
			cout << -1;
		else
			cout << b;
	}
}