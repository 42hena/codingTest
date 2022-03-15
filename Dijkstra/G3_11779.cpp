#include <bits/stdc++.h>
using namespace std;

int n, m;   // n: 도시의 개수 m: 버스의 개수
struct City
{
    int v, cost;
    bool operator<(const struct City &copy) const
    {
        return cost > copy.cost;
    }
};
int start, dest;
vector<City> graph[1001];
int record[1001];
int dist[1001];
void dijkstra()
{
    priority_queue<City> pq;
    pq.push({start, 0});
    record[start] = start;
    while (!pq.empty())
    {
        City now = pq.top(); pq.pop();
        
        if (dist[now.v] < now.cost) continue;

        for (int i = 0 ; i < graph[now.v].size() ; ++i)
        {
            int next = graph[now.v][i].v;
            int nextCost = graph[now.v][i].cost + now.cost;
            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                record[next] = now.v;
                pq.push({next, nextCost});
            }
        }
    }
}

#define INF 1000000009

void getPath()
{
    stack<int> s;
    s.push(dest);
    int now = dest;
    while (now != start)
    {
        // cout << "tq";
        s.push(record[now]);
        now = record[now];
    }
    int pathCount = s.size();
    cout << dist[dest] << '\n';
    cout << pathCount << '\n';
    while (!s.empty())
    {
        cout << s.top() <<' ';
        s.pop();
    }
}
int main()
{
    cin >> n >> m;

    int v1, v2, w;
    for (int i = 1 ; i <= n ; ++i)
    {
        dist[i] = INF;
    }
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
    }
    cin >> start >> dest;
    dijkstra();
    getPath();
}