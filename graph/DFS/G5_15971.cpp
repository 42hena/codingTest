#include <bits/stdc++.h>
using namespace std;
struct Data{
    int v;
    int w;
};
#define MAX 100001
vector<Data> graph[MAX];
bool visited[MAX];
int costArray[MAX];
int n, robot1, robot2;
int maxLength;
void DFS(int now, int nowCost, int maxValue)
{
    visited[now] = true;
    if (now == robot2)
    {
        maxLength = maxValue;
        return ;
    }
    for (int i = 0 ; i < graph[now].size() ; ++i)
    {
        int next = graph[now][i].v;
        int nextCost = graph[now][i].w + nowCost;
        int tmpMax = maxValue;
        if (!visited[next])
        {
            maxValue = max(maxValue, graph[now][i].w);
            costArray[next] = nextCost;
            DFS(next, nextCost, maxValue);
        }
        maxValue = tmpMax;
    }
}
int main()
{
    
    cin >> n >> robot1 >> robot2;

    int v1, v2, w;

    for (int i = 0 ; i < n - 1; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }
    DFS(robot1, 0, 0);
    cout << costArray[robot2] - maxLength;
}