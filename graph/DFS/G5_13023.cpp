#include <bits/stdc++.h>
using namespace std;

vector<int> graph[2000];
int visited[2000] = {0};
int ans;

void DFS(int start, int count)
{
    if (ans)
        return ;
    if (count == 5)
    {
        ans = 1;
        return ;
    }
    for (int i = 0 ; i < graph[start].size() ; ++i)
    {
        int next = graph[start][i];
        if (!visited[next])
        {
            visited[next] = true;
            DFS(next, count + 1);
            visited[next] = false;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int v1, v2;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (int i = 0 ; i < n ; ++i)
    {
        visited[i] = true;
        DFS(i, 1);
        visited[i] = false;
    }
    cout << ans;
}