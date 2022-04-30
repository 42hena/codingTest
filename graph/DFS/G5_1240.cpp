#include <bits/stdc++.h>
using namespace std;

struct Data
{
    int v, w;
};
#define MAX 1001
vector<Data> graph[MAX];
bool visited[MAX];
int answer;

int n, m;
int v1, v2, w;
void DFS(int now, int nowCost)
{
    visited[now] = true;
    if (now == v2)
    {
        answer = nowCost;
        return ;
    }
    for (int i = 0 ; i < graph[now].size() ; ++i)
    {
        int next = graph[now][i].v;
        int nextCost = graph[now][i].w + nowCost;
        if (visited[next])      continue;
        DFS(next, nextCost);
    }
}

int main()
{
    cin >> n >> m;

    
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
    }

    for (int i = 0 ; i < m ; ++i)
    {
        memset(visited, 0, sizeof(visited));
        cin >> v1 >> v2;
        DFS(v1, 0);
        cout << answer << '\n';
    }
}