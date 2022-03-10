#include <bits/stdc++.h>
using namespace std;
struct Data{
    int v;
    long long w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};
int n, m;
vector<Data> graph[100000];
long long dist[100000];
bool sight[100000];

void dijkstra()
{
    priority_queue<Data> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int now = pq.top().v;
        long long nowCost = pq.top().w;
        pq.pop();
        if (dist[now] < nowCost)
            continue;
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            long long nextCost = graph[now][i].w + dist[now];
            if (nextCost < dist[next] && !sight[next])
            {
                dist[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
    if (dist[n - 1] == 30000000001)
        cout << -1;
    else
        cout << dist[n- 1];
}
int main()
{
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> sight[i];
        dist[i] = 30000000001;
    }

    sight[n-1]=false;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i){
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    dijkstra();
}