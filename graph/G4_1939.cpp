#include <bits/stdc++.h>
using namespace std;

struct Data{
    int v, w;
    bool operator<(const struct Data &copy)const
    {
        return w < copy.w;
    }
};
vector<Data> graph[10001];
bool visited[10001];
int main()
{
    int n, m;
    cin >> n >> m;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    int start, end;
    cin >> start >> end;
    priority_queue<Data> pq;
    pq.push({start, 1000000000});
    int ans = 1000000000;
    while (!pq.empty())
    {
        int now = pq.top().v;
        int nowCost = pq.top().w;
        visited[now] = true;
        pq.pop();
        if (now == end)
        {
            ans = nowCost;
            break;
        }
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            int nextCost = graph[now][i].w;
            if (!visited[next])
            {
                nextCost = min(nowCost, nextCost);
                pq.push({next, nextCost});
            }
        }
    }
    cout << ans;
}