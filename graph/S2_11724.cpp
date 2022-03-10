#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void depth_first_search(vector<vector<int>> &graph, vector<bool> 
&visited, int vertex)
{
    if (visited[vertex])
        return ;
    int ret = 0;
    visited[vertex] = true;
    for (auto v : graph[vertex])
        depth_first_search(graph, visited, v);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    
    int a, b;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count  = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        
        if (!visited[i]){
            count++;
            depth_first_search(graph, visited, i);
        }
            
    }
    cout << count << endl;
}