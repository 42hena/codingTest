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
vector<Data> graph[10001];
int dist[10001];
int s, e;
void dijkstra()
{
    priority_queue<Data> pq;
    pq.push({s, 0});
    dist[s] = 0;

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
    
}
int main()
{
    while (true)
    {
        cin >> n >> m >> s >> e;
        if (n == m && m == s && s == e && e == 0)
            break;
        int v1, v2, w;
        for (int i = 1 ; i <= n ; ++i)
        {
            graph[i].clear();
        }
        for (int i = 0 ; i < m ; ++i)
        {
            cin >> v1 >> v2 >> w;
            graph[v1].push_back({v2, w});
        }
        for (int i = 1 ; i <= n ; ++i)
            dist[i] = 2147483647;
        dijkstra();
        cout << dist[e] << '\n';    
    }
}