#include <bits/stdc++.h>
using namespace std;

vector<int> graph[101];
bool visited[101];
bool ans[101];
void DFS(int start, int end, vector<int> &tmp)
{
    if (start == end)
    {
        for (int i = 0 ; i < tmp.size() ; ++i)
            ans[tmp[i]] = true;
        return ;
    }
    for (int i = 0 ; i < graph[start].size() ; ++i)
    {
        int next = graph[start][i];
        if (!visited[next])
        {
            visited[next] = true;
            tmp.push_back(next);
            DFS(next, end, tmp);
            visited[next] = false;
            tmp.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int vertex;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> vertex;
        graph[i + 1].push_back(vertex);
    }
    for (int i = 0 ; i < n ; ++i)
    {
        vector<int> tmp;
        tmp.push_back(i + 1);
        DFS(graph[i + 1][0], i + 1, tmp);
        tmp.pop_back();
    }
    int count = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (ans[i])
            count ++;
    }
    cout << count << '\n';
    for (int i = 1 ; i < n + 1 ; ++i)
    {
        if (ans[i])
            cout << i << '\n';
    }
}