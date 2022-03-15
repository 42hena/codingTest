#include <bits/stdc++.h>
using namespace std;

struct Computer{
    int v, time;
    bool operator<(const struct Computer &copy) const
    {
        return time > copy.time;
    }
};
int n, d, c;
int v1, v2, w;
vector<Computer> computer[10001];
int dist[10001];
#define INF 1000000009
void dijkstra()
{
    for (int i = 1 ; i <= n ; ++i)
        dist[i] = INF;
    
    dist[c] = 0;
    priority_queue<Computer> pq;
    pq.push({c, 0});

    while (!pq.empty())
    {
        Computer now = pq.top();
        pq.pop();

        if (dist[now.v] < now.time) continue;

        for (int i = 0 ; i < computer[now.v].size() ; ++i)
        {
            int next = computer[now.v][i].v;
            int nextTime = computer[now.v][i].time + now.time;
            if (nextTime < dist[next])
            {
                dist[next] = nextTime;
                pq.push({next, nextTime});
            }
        }
    }
    int virusComputerCount = 0;
    int maxTime = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (dist[i] != INF)
        {
            virusComputerCount++;
            maxTime = max(maxTime, dist[i]);
        }
    }
    cout << virusComputerCount << ' ' << maxTime << '\n';

}
int main()
{
    int testCaseNum;
    cin >> testCaseNum;
    
    while (testCaseNum --)
    {
        for (int i = 1 ; i <= n ; ++i)
        {
            computer[i].clear();   
        }
        cin >> n >> d >> c;
        for (int i = 0 ; i < d ; ++i)
        {
            cin >> v1 >> v2 >> w;
            computer[v2].push_back({v1, w});
        }
        dijkstra();
    }
}