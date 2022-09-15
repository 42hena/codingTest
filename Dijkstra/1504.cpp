#include <bits/stdc++.h>
using namespace std;

struct Data
{
	int vertex, cost;
	bool operator<(const Data &ref) const
	{
		return cost > ref.cost;
	}
};
vector<Data> graph[801];
int cost_path1[801];
int cost_path2[801];
int n, e;
void dijkstra(int start, int cost[])
{
	// init
	for (int i = 0 ; i < n + 1 ; ++i)
		cost[i] = 1e8;
	
	cost[start] = 0;
	priority_queue<Data> pq;
	pq.push({start, 0});

	while (!pq.empty())
	{
		int now_vertex = pq.top().vertex;
		int now_weight = pq.top().cost;
		// cout << now_vertex << ' ' << now_weight << '\n';
		pq.pop();
		if (now_weight > cost[now_vertex])
			continue;
		
		for (int i = 0 ; i < graph[now_vertex].size() ; ++i)
		{
			int next_vertex = graph[now_vertex][i].vertex;
			int next_weight = graph[now_vertex][i].cost;
			// cout << next_vertex << ' ' << next_weight << '\n';
			if (cost[next_vertex] > next_weight + cost[now_vertex])
			{
				cost[next_vertex] = next_weight + cost[now_vertex];
				pq.push({next_vertex, cost[next_vertex]});
			}
		}
	}

}



int main()
{
	cin >> n >> e;

	for (int i = 0 ; i < e ; ++i)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		graph[v1].push_back({v2, w});
		graph[v2].push_back({v1, w});
	}

	int path1, path2;
	cin >> path1 >> path2;
	dijkstra(path1, cost_path1);
	dijkstra(path2, cost_path2);
	int a = cost_path1[1] + cost_path1[path2] + cost_path2[n];
	int b = cost_path2[1] + cost_path2[path1] + cost_path1[n];
	if (a >= 1e8 || b >= 1e8)
		cout << -1;
	else
		cout << min(a, b);
}
// overflow를 조심하세요