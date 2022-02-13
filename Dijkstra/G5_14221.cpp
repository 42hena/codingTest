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
int s, e;
int h, c;

void dijkstra(int start)
{
    priority_queue<Data> pq;
    pq.push({start, 0});
    dist[start] = 0;

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
    cin >> n >> m;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    pair<int, int> re = {0, 2147483647};
    
    cin >> h >> c;
    vector<int> home(h);
    vector<int> conv(c);
    int num;
    for (int i = 0 ; i < h ; ++i){
        cin >> num;
        home[i] = num;
    }
    for (int i = 0 ; i < c ; ++i){
        cin >> num;
        conv[i] = num;
    }
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = 2147483647;
    for (int i = 0 ; i < h ; ++i){
        dijkstra(home[i]);
        for (int j = 0 ; j < c ; ++j)
        {
            if (dist[conv[j]] < re.second)
                re = {home[i], dist[conv[j]]};
        }
    }
    cout << re.first;
}