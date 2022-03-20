#include <bits/stdc++.h>
using namespace std;
int graph[101][101];
int main()
{
    const int INF = 1e9;
    int n, m;
    cin >> n >> m;
    vector<int> paths;
    int path;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> path;
        paths.push_back(path);
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= n ; ++j)
        {
            cin >> graph[i][j];
        }
    }   
    for (int k = 1 ; k <= n ; ++k)
    {
        for (int i = 1 ; i <= n ; ++i)
        {
            for (int j = 1 ; j <= n ; ++j)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }   
    }
    int sum = 0;
    int start = paths[0];
    for (int i = 1 ; i < m ; ++i)
    {
        int end = paths[i];
        sum += graph[start][end];
        start = end;
    }
    cout << sum;
}