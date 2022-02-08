#include <bits/stdc++.h>
using namespace std;
//n: 지름길의 개수
//d: 고속도로의 길이
int n, d;
#define INF 2147483647
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
void dijkstra(int start)
{
    for (int i = 0 ; i <= 10001 ; ++i)
        dist[i] = INF;
    dist[start] = 0;
    priority_queue<Data> pq;
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
            int nextCost = graph[now][i].w + nowCost;
            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
    cout << dist[d];
}
int main()
{
    cin >> n >> d;
    int v1, v2, w;
    for (int i = 0 ; i < n ; ++i){
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    for (int i = 0 ; i < d ; ++i){
        graph[i].push_back({i + 1, 1});
    }
    dijkstra(0);
}