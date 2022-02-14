//https://www.acmicpc.net/problem/18352
//특정 거리의 도시 찾기
#include <bits/stdc++.h>
using namespace std;
//N:도시 개수
//M:도로 개수
//K:거리 정보
//X:출발 도시
#define INF 2147483647
int n, m, k, x;
struct Data{
    int v;
    int w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};
vector<Data> graph[300001];

void dijkstra(int start, int weight)
{
    priority_queue<Data> pq;
    int dist[300001];
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = INF;
    dist[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        int now = pq.top().v;
        int nowCost= pq.top().w;
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
    bool flag = true;
    for (int i = 1 ; i <= n ; ++i)
        if (dist[i] == weight){
            cout << i << '\n';
            flag = false;
        }
    if (flag)
        cout << -1;
}
int main()
{
    cin >> n >> m >> k >> x;
    int v1, v2;
    for (int i = 0 ; i < m ; ++i){
        cin >> v1 >> v2;
        graph[v1].push_back({v2, 1});
    }
    dijkstra(x, k);
}