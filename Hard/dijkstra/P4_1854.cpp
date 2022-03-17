#include <bits/stdc++.h>
using namespace std;
struct City
{
    int v, w;
    bool operator<(const City &copy) const
    {
        return w > copy.w;
    }
};
priority_queue<int, vector<int>, less<int>> city[1001]; 
int n, m, k;
vector<City> graph[1001];

void dijkstra()
{
    priority_queue<City> pq;
    city[1].push(0);
    pq.push({1, 0});

    while (!pq.empty())
    {
        int now = pq.top().v;
        int nowCost = pq.top().w;
        pq.pop();
        // if (dist[now] < nowCost)    continue;
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            int nextCost = graph[now][i].w + nowCost;
            // cout << next << ' ' << nextCost << '\n';
            
            if (city[next].size() < k)
            {
                city[next].push(nextCost);
                pq.push({next, nextCost});
            }
            else{
                if (nextCost < city[next].top())
                {
                    city[next].pop();
                    city[next].push(nextCost);
                    pq.push({next, nextCost});
                }
            }
            
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    int a, b, c;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    dijkstra();
    for (int i = 1 ; i <= n ; ++i)
    {
        if (city[i].size() == k)
        {
            cout << city[i].top() << '\n';
        }
        else
            cout << -1 << '\n';
    }
}