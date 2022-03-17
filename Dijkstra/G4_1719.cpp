#include <bits/stdc++.h>
using namespace std;
struct DropPoint{
    int v, w;
    bool operator<(const DropPoint &copy) const
    {
        return w > copy.w;
    }
};
int dist[201];
int path[201];
int ans[201][201];
int n, m;
vector<DropPoint> graph[201];
void init()
{
    memset(dist, 127, sizeof(dist));
}

void dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<DropPoint> pq;

    pq.push({start, 0});
    while (!pq.empty())
    {
        int now = pq.top().v;
        int nowCost = pq.top().w;
        pq.pop();
        if (dist[now] < nowCost)    continue;
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            int nextCost = graph[now][i].w + nowCost;
            if (nextCost < dist[next])
            {
                path[next] = now;
                dist[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
    
}
int main()
{
    cin >> n >> m;
    int v1, v2, w;

    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }

    for (int i = 1 ; i <=n ; ++i)
    {
        init();
        dijkstra(i);
        for (int j = 1 ; j <= n ; ++j)
            ans[j][i] = path[j];
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= n ; ++j)
        {
            if (i == j)
                cout << '-' << ' ';
            else
                cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}