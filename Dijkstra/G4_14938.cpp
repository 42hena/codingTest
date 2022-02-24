#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int v, w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};

int n, m, r;
int itemCount[101];
int dist[101];
int ans;
vector<Data> graph[101];

void dijkstra(int start)
{
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = 2147483647;
    priority_queue<Data> pq;
    dist[start] = 0;
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
    int sum = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (dist[i] <= m)
            sum += itemCount[i];
    }
    ans = max(ans, sum);
}
int main()
{
    cin >> n >> m >> r;
    for (int i = 1 ; i <= n ; ++i)
        cin >> itemCount[i];
    int v1, v2, w;
    for (int i = 0 ; i < r ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    for (int i = 1 ; i<= n ; ++i)
    {
        dijkstra(i);
    }
    cout << ans;
}