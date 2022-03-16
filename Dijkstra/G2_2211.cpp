#include <bits/stdc++.h>
using namespace std;
struct Network
{
    int v, w;
    bool operator<(const Network &copy)const
    {
        return w > copy.w;
    }
};

vector<Network> graph[1001];
int dist[1001];
int path[1001];

int n, m;
int a, b, c;
void init()
{
    memset(dist, 127, sizeof(dist));
    memset(graph, 0, sizeof(graph));
}
void dijkstra()
{
    priority_queue<Network> pq;
    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty())
    {
        int now = pq.top().v;
        int nowCost = pq.top().w;
        pq.pop();
        if (dist[now] < nowCost)    continue;

        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            int nextCost = graph[now][i].w + nowCost;
            if (nextCost < dist[next])
            {
                path[next] = now;
                dist[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    init();
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    dijkstra();
    set<pair<int, int>> s;
    for (int i = 1; i<= n ; ++i)
    {
        int now = i;
        while (path[now] != 0)
        {
            int prev = path[now];
            s.insert({prev, now});
            now = prev;
        }
        
    }
    
    int count = s.size();
    cout << count <<'\n';
    for (auto value : s)
    {
        cout << value.first << ' ' << value.second <<'\n';
    }
}