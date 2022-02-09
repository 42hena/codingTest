#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int n, m, x;
struct Data{
    int v;
    int w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};

void dijkstra(vector<Data> (&graph)[1001], int start, vector<int> &d)
{
    d[start] = 0;
    
    priority_queue<Data> pq;
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
}

int main()
{
    vector<Data> come[1001];
    vector<Data> back[1001];
    vector<int> dist_come(1001, INF);
    vector<int> dist_back(1001, INF);
    cin >> n >> m >> x;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i){
        cin >> v1 >> v2 >> w;
        come[v1].push_back({v2, w});
        back[v2].push_back({v1, w});
    }
    for (int i = 1 ; i<= n ; ++i)
    {
        dist_come[i] = INF;
        dist_back[i] = INF;
    }
    dijkstra(come, x, dist_come);
    dijkstra(back, x, dist_back);
    int maxValue = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        // cout << dist_come[i] << ' ' << dist_back[i] << '\n';
        int total = dist_come[i] + dist_back[i];
        if (total <= INF && total > maxValue)
            maxValue = total;
    }
    cout << maxValue;
}