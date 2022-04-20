#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
int visited[10001];
int cache[10001];
int cnt;
void DFS(int nowVertex)
{
    visited[nowVertex] = true;
    for (int i = 0 ; i < graph[nowVertex].size() ; ++i)
    {
        int next = graph[nowVertex][i];
        if (!visited[next])
        {
            cnt++;
            DFS(next);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    int v1, v2;
    for (int i = 0; i < m ; ++i)
    {
        cin >> v1 >> v2;
        graph[v2].push_back(v1);
    }
    memset(cache, -1, sizeof(cache));
    int maxDepth = 0;
    vector<int> v;
    for (int i = 1 ; i < n + 1 ; ++i)
    {
        cnt = 0;
        DFS(i);
        memset(visited, 0, sizeof(visited));
        if (cnt > maxDepth)
        {
            maxDepth = cnt;
            v.clear();
            v.push_back(i);
        }
        else if (cnt == maxDepth)
            v.push_back(i);
    }
    for (int i = 0 ; i < v.size() ; ++i)
    {
        cout << v[i] << ' ';
    }   
}