#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
struct Data
{
    int v;
    int w;
    bool operator<(const struct Data &copy)const
    {
        return w > copy.w;
    }
};

int n, k;
vector<Data> graph[101];
int dist[101];

void dijkstra(int start, int end)
{
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = INF;
    dist[start] = 0;
    priority_queue<Data> pq;
    pq.push({start, 0});

    while(!pq.empty())
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
    if (dist[end] == INF)
        cout << -1 << '\n';
    else
        cout << dist[end] << '\n';
}

int main(void)
{
    cin >> n >> k;
    int type;
    int v1, v2, w;
    int start, end;
    for (int i = 0 ; i < k ; ++i)
    {
        cin >> type;
        if (type == 0)
        {
            cin >> start >> end;
            dijkstra(start, end);
        }
        else
        {
            cin >> v1 >> v2 >> w;
            graph[v1].push_back({v2, w});
            graph[v2].push_back({v1, w});
        }
    }
}