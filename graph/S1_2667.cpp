#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int depth_first_search(vector<vector<bool>> &graph, vector<vector<bool>> &visited, int x, int y, int n, int cnt)
{
    if (visited[x][y])
        return 0;
    int ret = 0;
    visited[x][y] = true;
    for (int i = 0 ; i < 4 ; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (graph[nx][ny])
            ret += depth_first_search(graph, visited, nx, ny, n, cnt + 1);
    }
    return 1 + ret;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> graph(n, vector<bool>(n, false)), visited(n, vector<bool>(n, false));

    for (int i = 0 ; i < n ; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0 ; j < n ; ++j)
        {
            str[j] == '1' ? graph[i][j] = true : graph[i][j] = false;
        }
    }
    vector<int> housesNum;
    int count = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < n ; ++j)
        {   
            if (!visited[i][j] && graph[i][j]){
                count++;
                int num = depth_first_search(graph, visited, i, j, n, 0);
                housesNum.push_back(num);
                // memset(visited, false, sizeof(visited));
            }
        }
    }
    cout << count << endl;
    sort(housesNum.begin(), housesNum.end());
    for (auto i : housesNum)
        cout << i << endl;
    
}