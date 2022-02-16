#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c;// n: 정점의 개수, m: 골목 개수
//a: 시작점, b: 도착점, c: 가진 돈

//구조체
struct Data
{
    int v, w, shame;//v: 연결된 정점, w: 가중치, w: 수치심
    bool operator<(const struct Data &copy) const
    {
        if (w == copy.w)
            return w > copy.w;
        return shame > copy.shame;//수치심(정렬) -> 가중치(정렬) 순으로 정렬
    }
};

vector<Data> graph[11];
int dist[11];


void dijstra(int start, int end, int money)
{
    int maxShame = 1001;        // 골목 수금액이 1000이라서 1001로 최대치 고정
    priority_queue<Data> pq;
    dist[start] = 0;            // 시작 지점은 돈을 내지 않음

    pq.push({start, 0, 0});     // 시작 지점 start, weight, shame 순

    while (!pq.empty())
    {
        int now = pq.top().v;       // 현재 정점
        int nowCost = pq.top().w;   // 현재 가중치
        int shame = pq.top().shame; // 현재 수치심
        // cout << now << ' ' << nowCost << ' ' << shame << '\n';
        pq.pop();
        
        if (nowCost > money)        // 현재 돈보다 가중치가 크다면 무시
            continue;
        if (now == end && shame < maxShame) //현재 정점이 도착점이고, 수치심이 적다면 갱신하는 부분
            maxShame = shame;
        
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            int nextCost = graph[now][i].w + dist[now];
            int nextShame = (shame < graph[now][i].shame ? graph[now][i].shame : shame);
            if (nextCost < dist[next] && nextCost <= money )
            {
                dist[next] = nextCost;
                pq.push({next, nextCost, nextShame});
            }
        }
    }
    if (maxShame == 1001 || dist[end] ==  2147483647)
        cout << -1;
    else
        cout << maxShame;
}

void FastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main(void)
{
    FastIO();
    cin >> n >> m >> a >> b >> c;  
    int v1, v2, w;  
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = 2147483647;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w, w});
        graph[v2].push_back({v1, w, w});
    }
    dijstra(a, b, c);
}