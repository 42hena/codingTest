#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;// n: 정점의 개수, m: 골목 개수
//a: 시작점, b: 도착점, c: 가진 돈

//구조체
struct Data
{
    int v, w;
    bool operator<(const struct Data &copy) const
    {
        return w > copy.w;
    }
};

vector<Data> graph[11];
int dist[11];
int maxShame = 1001;


// void dijstra(int start, int end, int money)
// {
//     priority_queue<Data> pq;
//     dist[start] = 0;            // 시작 지점은 돈을 내지 않음
//     pq.push({start, 0});     // 시작 지점 start, weight, shame 순
//     while (!pq.empty())
//     {
//         int now = pq.top().v;       // 현재 정점
//         int nowCost = pq.top().w;   // 현재 가중치
//         cout << now << ' ' << nowCost<< '\n';
//         pq.pop();     
//         if (nowCost > money)        // 현재 돈보다 가중치가 크다면 무시
//             continue; 
//         for (int i = 0 ; i < graph[now].size() ; ++i)
//         {
//             int next = graph[now][i].v;
//             int nextCost = graph[now][i].w;
//             if (dist[next] >= money && dist[now] + nextCost < dist[next])
//             {
//                 dist[next] = nextCost + dist[now];
//                 pq.push({next, dist[next]});
//             }
//         }
//     }
//     cout << '\n';
// }

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
bool visited[11];
void DFS(int v, int c, int cost, int shame)
{
    cout << v << ' ' <<  cost <<' ' << shame<< '\n';
    if (c < cost)
        return ;
    if (v == b)
    {
        if (maxShame > shame)
            maxShame = shame;
        return ;
    }
    
    
    for (int i = 0 ; i < graph[v].size() ; ++i)
    {
        int next = graph[v][i].v;
        int nextCost = graph[v][i].w + cost;
        int nshame = max(shame, graph[v][i].w);
        if (!visited[next])
        {
            visited[next] = true;
            DFS(next, c, nextCost, nshame);
            visited[next] = false;
        }
    }
}

int main(void)
{
    FastIO();
    cin >> n >> m >> a >> b >> c;  
    int v1, v2, w;
    int cnt = 0;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = 2147483647;
    visited[a] = true;
    DFS(a, c, 0, 0);
    // dijstra(a, b, cnt);
    // cout << cnt << ": " <<maxShame << '\n';
    if (maxShame ==  1001)
        cout << -1;
    else
        cout << maxShame;
}