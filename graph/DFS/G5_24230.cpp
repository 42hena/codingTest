#include <bits/stdc++.h>
using namespace std;

#define MAX 200001
int colors[MAX];
bool visited[MAX];
int n;
int answer;
vector<int> graph[MAX];
void DFS(int now)
{
    visited[now] = true;
    int color = colors[now];
    for (int i = 0 ; i < graph[now].size() ; ++i)
    {
        int next = graph[now][i];
        if (visited[next])  continue;
        if (colors[next] != color)
            answer++;
        DFS(next);
    }
}
int main()
{
    cin >> n;
    for (int i = 1 ; i < n + 1 ; ++i)
        cin >> colors[i];
    int v1, v2;
    for (int i = 0 ; i < n - 1 ; ++i)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    DFS(1);
    if (colors[1] != 0)
        answer++;
    cout << answer;
}