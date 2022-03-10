#include <bits/stdc++.h>

using namespace std;
#define INF 2147483647

struct Data{
    int v;
    int w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};
int start, dst;
int n, m;
vector<Data> graph[1001];
int d[1001];

void dijkstra()
{
    priority_queue<Data> pq;
    d[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        int now = pq.top().v;
        int nowCost = pq.top().w;
        pq.pop();
        
        if (d[now] < nowCost)
            continue;
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            int nextCost = graph[now][i].w + d[now];
            if (nextCost < d[next])
            {
                d[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
    if (d[dst] == INF)
        cout << -1;
    else
        cout << d[dst];
}

int main()
{
    cin >> start >> dst >> n >> m;
    int v1, v2;
    for(int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2;
        graph[v1].push_back({v2, 1});
        graph[v2].push_back({v1, 1});
    }
    for (int i = 0 ; i <= n ; ++i)
        d[i] = INF;

    dijkstra();
}