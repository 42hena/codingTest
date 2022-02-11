#include <bits/stdc++.h>
using namespace std;
int n, m;

struct Data{
    int v;
    int w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};
vector<Data> graph[50001];
int dist[50001];

void dijkstra()
{
    priority_queue<Data> pq;
    pq.push({1, 0});
    dist[1] = 0;

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

            if (nextCost < dist[next]){
                dist[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
    cout << dist[n];
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
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = 2147483647;
    dijkstra();
}