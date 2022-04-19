#include <bits/stdc++.h>


using namespace std;
#define MAX 20001
bool visited[MAX];
vector<int> graph[MAX];
struct Data
{
    int v, cnt;
};
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    // graph 초기화
    for (int i = 0 ; i < edge.size() ; ++i)
    {
        int v1 = edge[i][0];
        int v2 = edge[i][1];
        // cout << v1 << v2 << '\n';
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // BFS 돌리기
    queue<Data> q;
    q.push({1, 0});
    visited[1] = true;
    vector<int> farNode;
    
    int maxSize = 0;
    while (!q.empty())
    {
        int now = q.front().v; 
        int count = q.front().cnt;q.pop();
        if (count > maxSize)
        {
            maxSize = count;
            farNode.clear();
            farNode.push_back(now);
        }
        else if (count == maxSize)
            farNode.push_back(now);
        for (int i = 0 ;i < graph[now].size() ; ++i)
        {
            int next = graph[now][i];
            if (!visited[next])
            {
                visited[next] = true;
                q.push({next, count + 1});
            }
        }   
    }
    return answer = farNode.size();
}