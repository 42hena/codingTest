#include <bits/stdc++.h>
using namespace std;
int n, m, k;


#define INF 1e15

struct City{
    int v;
    long long w;
    int cnt;
    bool operator<(const City &copy) const
    {
        return w > copy.w;
    }
};
vector<City> graph[10001];
long long int dp[10001][21];
void dijkstra()
{
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = INF;
        }
    }
    priority_queue<City> pq;
    pq.push({1, 0});
    dp[1][0] = 0;

    while (!pq.empty())
    {
        int now = pq.top().v;
        long long int nowCost = pq.top().w;
        int cnt = pq.top().cnt;
        pq.pop();
        if (dp[now][cnt] < nowCost) continue;

        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            long long int nextCost = graph[now][i].w + nowCost;
            int nextCnt = graph[now][i].cnt;
            if (nextCost < dp[next][cnt])
            {
                dp[next][cnt] = nextCost;
                pq.push({next, nextCost, cnt});
            }

            if (nowCost < dp[next][cnt + 1] && cnt + 1 <= k)
            {
                dp[next][cnt + 1] = nowCost;
                pq.push({next, nowCost, cnt + 1});
            }
        }
    }

}

int main()
{
    cin >> n >> m >> k;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    long long int ans = INF;
    dijkstra();    
    for (int i = 0 ; i <= k ; ++i)
        ans = min(ans, dp[n][i]);

    cout << ans;
}