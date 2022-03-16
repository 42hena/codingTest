#include <bits/stdc++.h>
using namespace std;
int n, m;
int s, d;
int u, v, p;

struct Path
{
    int vertex, cost;
    bool operator<(const Path &copy) const
    {
        return cost > copy.cost;
    }
};

vector<Path> graph[500];
vector<int> trace[500];
int dist[500];
bool visited[500];

void init() {
    memset(graph, 0, sizeof(gragh));
    memset(trace, 0, sizeof(trace));
    memset(dist, 127, sizeof(dist));
    memset(visited, false, sizeof(visited));
}
void dijkstra()
{
    dist[s] = 0;
    priority_queue<Path> pq;
    pq.push({s, 0});

    while (!pq.empty())
    {
        int now = pq.top().vertex;
        int nowCost = pq.top().cost;
        pq.pop();

        if (dist[now] < nowCost)    continue;

        for (int i = 0; i < graph[now].size(); ++i)
        {
            int next = graph[now][i].vertex;
            int nextCost = graph[now][i].cost + dist[now];
            if (graph[now][i].cost == -1)
                continue;

            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push({next, nextCost});

                trace[next].clear();
                trace[next].push_back(now);
            }
            else if (nextCost == dist[next])
                trace[next].push_back(now);
        }
    }
}

void BFS()
{
    queue<int> q;
    q.push(d);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (visited[now]) continue;
        visited[now] = true;
        for (int i = 0; i < trace[now].size(); i++)
        {
            int next = trace[now][i];
            for (int j = 0; j < graph[next].size(); j++)
                if (graph[next][j].vertex == now)
                    graph[next][j].cost = -1;
            q.push(next);
        }
    }
}

int main()
{
    while (true)
    {
        cin >> n >> m;
        if (n == m && m == 0)
            break;
        cin >> s >> d;
        init();
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> p;
            graph[u].push_back({v, p});
        }
        int INF = dist[0];
        
        dijkstra();
        BFS();
        memset(dist, 127, sizeof(dist));
        dijkstra();

        if (dist[d] == INF) cout << -1 << '\n';
        else                cout << dist[d] << '\n';
    }
}