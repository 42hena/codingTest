#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 2147483647
vector<pair<int, int>> graph[20001];
int d[20001];
int vertexNum, edgeNum;
int startNode;
priority_queue<pair<int, int> > pq;
void dikstra()
{
    d[startNode] = 0;
    pq.push({0, startNode});//weight, startNode

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist)
            continue;

        for (int i = 0 ; i < graph[now].size(); ++i)
        {
            int cost = dist + graph[now][i].second;

            if (cost < d[graph[now][i].first])
            {
                d[graph[now][i].first] = cost;
                pq.push({-cost, graph[now][i].first});
            } 
        }
    }
    
}


int main()
{
    
    cin >> vertexNum >> edgeNum >> startNode;
    int u, v, w;
    for (int i = 1 ; i <= vertexNum ; ++i)
        d[i] = INF;
    for (int i = 0 ; i < edgeNum ; ++i)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w});
    }
    dikstra();   
    for (int i =1 ; i <= vertexNum ; ++i){
        if (d[i] != INF)
            cout << d[i] << endl;
        else
            cout << "INF" << endl;
    }
}