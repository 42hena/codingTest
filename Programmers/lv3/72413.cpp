#include <bits/stdc++.h>

using namespace std;
struct Data{
    int vertex;
    int weight;
    Data(int vertex, int weight) : vertex(vertex), weight(weight){}
    bool operator<(const struct Data copy) const
    {
        return weight > copy.weight;
    }
};
vector<pair<int, int>> graph[201];

void graphInit(vector<vector<int>> &fares, int &n)
{
    int v1, v2, w;
    for (int i = 0 ; i < fares.size() ; ++i)
    {
        // v1 = ;
        // v2 = ;
        // w = ;
        // cout << v1 << ' ' << v2 << ' ' << w<< '\n';
        graph[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        graph[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
}

void dijstra(vector<int>& d, int &start, const int &end, int &n)
{
    int v, cost;
    int next, nextCost;

    priority_queue<pair<int, int>> pq;
    d[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty())
    {
        int w = -pq.top().first;
        int x = pq.top().second; pq.pop();
        
        if (d[x] < w)
            continue;
        for (int i = 0 ; i < graph[x].size() ; ++i)
        {
            int nx = graph[x][i].first;
            int nw = w + graph[x][i].second;
            if (nw < d[nx])
            {
                d[nx] = nw;
                pq.push({-nw, nx});
            }
        }
    }
    // return d[end];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 2147483647;
    graphInit(fares, n);
    
    vector<int> SI(n + 1, 100000000);
    dijstra(SI, s, 1, n);
    vector<int> AI(n + 1, 100000000);
    dijstra(AI, a, 1, n);
    vector<int> BI(n + 1, 100000000);
    dijstra(BI, b, 1, n);
    
    for (int i = 1 ; i <= n ; ++i)
        answer = min(answer, AI[i] + BI[i] + SI[i]);
    return answer;
}