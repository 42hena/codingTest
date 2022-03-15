#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char board[100][100];
int dist[100][100][4];
int n, m, t;
int s, g, h;
int cx, cy;
#define INF 1000000009

struct Load
{
    int v, cost;
    bool operator< (const Load &copy) const
    {
        return cost > copy.cost;
    }
};
vector<Load> graph[2001];
int dist_s[2001];
int dist_g[2001];
int dist_h[2001];
int testCaseNum;
vector<int> candidate;
void Input()
{
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    int v1, v2, w;
    for (int i = 1 ; i <= n ; ++i)
    {
        dist_s[i] = dist_g[i] = dist_h[i] = INF;
        graph[i].clear();
        candidate.clear();
    }

    for (int i = 0  ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    int num;
    for (int i = 0  ; i < t ; ++i)
    {
        cin >> num;
        candidate.push_back(num);
    }
    sort(candidate.begin(), candidate.end());
}


void dijkstra(int start, int dist[])
{
    priority_queue<Load> pq;
    dist[start] = 0;
    pq.push({start, 0});

    
    while (!pq.empty())
    {
        Load now = pq.top();
        pq.pop();
        
        if (dist[now.v] < now.cost)
            continue;

        for (int i = 0 ; i < graph[now.v].size() ; ++i)
        {
            int next = graph[now.v][i].v;
            int nextCost = graph[now.v][i].cost + now.cost;
            if (nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
}

int main()
{
    cin >> testCaseNum;
    while (testCaseNum--)
    {
        Input();
        dijkstra(s, dist_s);
        dijkstra(g, dist_g);
        dijkstra(h, dist_h);
        int gTohCost = dist_g[h];
        for (auto value : candidate)
        {
            if (dist_s[value] == dist_s[g] + gTohCost + dist_h[value])
                cout << value << ' ';
            else if (dist_s[value] == dist_s[h] + gTohCost + dist_g[value])
                cout << value << ' ';
        }
        cout << '\n';
    }
}