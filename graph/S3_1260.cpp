//https://www.acmicpc.net/problem/1260
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool visited[1001];
void depth_first_search(vector<vector<int>> &graph, int index)
{
    if (visited[index])
        return ;
    visited[index] = true;
    cout << index << ' ';
    for (int i = 0 ; i < graph[index].size() ; ++i)
        depth_first_search(graph, graph[index][i]);
    return ;
}

void breadth_first_search(vector<vector<int>> &graph, int index)
{
    queue<int> q;
    
    q.push(index);
    visited[index] = true;
    while (!q.empty())
    {
        int v = q.front();
        cout << v << ' ';
        q.pop();

        for (int i = 0 ; i < graph[v].size() ; ++i){
            if (!visited[graph[v][i]]){
                q.push(graph[v][i]);
                visited[graph[v][i]] = true;
            }
        }
    }
}

int main(void)
{
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);

    vector<pair<int, int>> info(m, {0, 0});

    // 입력
    for (int i = 0 ; i < m ; ++i)
        cin >> info[i].first >> info[i].second;
    
    // graph에 넣기
    for (int i = 0 ; i < m ; ++i)
    {
        graph[info[i].first].push_back(info[i].second);
        graph[info[i].second].push_back(info[i].first);
    }

    // sorting
    for (int i = 1 ; i <= n ; ++i)
        sort(graph[i].begin(), graph[i].end());

    //DFS
    depth_first_search(graph, v);
    cout << endl;
    memset(visited, false, sizeof(visited));
    //BFS
    breadth_first_search(graph, v);
    
}