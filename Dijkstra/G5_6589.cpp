#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Data{
    int v;
    int w;
    bool operator<(const struct Data &copy) const
    {
        return w < copy.w;
    }
};

vector<Data> graph[200];
int weight[200];
#define INF 2147483647
void dijkstra(int start, int end)
{
    for (int i = 0 ; i < n ; ++i)
        weight[i] = 0;
    weight[start] = INF;
    priority_queue<Data> pq;
    pq.push({start, INF});

    while (!pq.empty())
    {
        int now = pq.top().v;
        int nowCost = pq.top().w;
        // cout << now <<' ' << nowCost << '\n';
        pq.pop();

        if (weight[now] > nowCost)
            continue;
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i].v;
            // int nextCost; = graph[now][i].w;
            int nextCost = graph[now][i].w > weight[now] ? weight[now] : graph[now][i].w;
            if (nextCost > weight[next])
            {
                weight[next] = nextCost;
                pq.push({next, nextCost});
            }
        }
    }
    // for (int i = 0 ; i < n ; ++i)
    // {
    //     cout << weight[i] << ' ';
    // }
    // cout << '\n';
}

int main(void)
{
    string v1, v2;
    int w;
    int casenum = 1;
    while (true)
    {
        map<string, int> dict;
        cin >> n >> m;
        int cnt = 0;
        if (n == 0 && m == 0)
            break;
        for (int i = 0 ; i < m ; ++i)
        {
            cin >> v1 >> v2 >> w;
            if (dict.find(v1) == dict.end())
            {
                dict.insert({v1, cnt});
                cnt++;
            }
            if (dict.find(v2) == dict.end())
            {
                dict.insert({v2, cnt});
                cnt++;
            }
            auto iterv1 = dict.find(v1);
            auto iterv2 = dict.find(v2);
            graph[iterv1->second].push_back({iterv2->second, w});
            graph[iterv2->second].push_back({iterv1->second, w});
        }
        cin >> v1 >> v2;
        int start = dict.find(v1)->second;
        int end = dict.find(v2)->second;

        dijkstra(start, end);
        cout << "Scenario #" << casenum <<'\n';
        cout << weight[end] <<" tons" << "\n\n";
        casenum++;
        for(int i = 0 ; i < n ; ++i)
            graph[i].clear();
    }
}