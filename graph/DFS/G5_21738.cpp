#include <bits/stdc++.h>
using namespace std;

#define MAX 328001
vector<int> graph[MAX];
int costs[MAX];
bool visited[MAX];

void dfs(int now, int count)
{
    visited[now] = true;
    costs[now] = count;
    for (int i = 0 ; i < graph[now].size() ; ++i)
    {
        int next = graph[now][i];
        // cout << next << '\n';
        if (visited[next])      continue;
        dfs(next, count + 1);
    }
}


int main()
{
    int n, s, p;

    cin >> n >> s >> p;

    int a, b;
    for (int i = 0 ; i < n - 1 ; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(p, 0);
    int minValue1, minValue2;
    vector<int> v;
    for (int i = 1 ; i < s + 1 ; ++i)
    {
        v.push_back(costs[i]);
    }
    sort(v.begin(), v.end());
    cout << n - v[0] - v[1] - 1;
}