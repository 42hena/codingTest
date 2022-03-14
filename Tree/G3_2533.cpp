#include <bits/stdc++.h>
using namespace std;
int dp[1000001][2];
// bool visited[1000001];
vector<int> graph[1000001];
bool visited[1000001];
void DFS(int v)
{
    dp[v][1] = 1;
    visited[v] = true;
    for (int i = 0 ; i < graph[v].size() ; ++i)
    {
        int child = graph[v][i];
        if (visited[child]) continue;
        DFS(child);
        dp[v][1] += min(dp[child][0], dp[child][1]);    
        dp[v][0] += dp[child][1];
    }
}


int main()
{
    int n;
    int v1, v2;

    cin >> n;
    for (int i = 0 ; i < n - 1 ; ++i)
    {
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    DFS(1);
    cout << min(dp[1][0], dp[1][1]);
}