#include <bits/stdc++.h>
using namespace std;
struct Data{
    int v;
    int w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};
int n, m, x;
vector<Data> graph[1001];
int dist[1001];

void dijkstra()
{
    priority_queue<Data> pq;
    dist[x] = 0;
    pq.push({x, 0});

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
    int maxValue = 0;
    for (int i = 1 ; i <= n ; ++i){
        maxValue = max(maxValue, dist[i]);
    }
    cout << maxValue * 2;
}
int main()
{
    cin >> n >> m >> x;
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = 2147483647;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i){
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    dijkstra();
}