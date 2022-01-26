#include <string>
#include <vector>
#include <bits/stdc++.h>
int sheepCnt = 0;
int wolfCnt = 0;
using namespace std;
vector<int> graph[17];
bool visited[17];
pair<int, int> value[17];

void preorder(int v, vector<int> &info, vector<vector<int>> &edges)
{
    if (!graph[v].size())
    {
        // if (info[v])
        //     value[v].second = 1;
        // else
        //     value[v].first = 1;
        return ;
    }
    for (int i = 0 ; i < graph[v].size() ; ++i)
    {
        preorder(graph[v][i], info, edges);    
    }
    if (graph[v].size() == 2){
            value[v].first += value[graph[v][0]].first + value[graph[v][1]].first;
            value[v].second += value[graph[v][0]].second + value[graph[v][1]].second;       
    }
    else if (graph[v].size() == 1){
        value[v].first += value[graph[v][0]].first;
        value[v].second += value[graph[v][0]].second;
    }
}

//     for i in graph[v]:
//         preorder(i, info, edges)

//     elif len(graph[v]) == 1:
//         value[v][0] += value[graph[v][0]][0]
//         value[v][1] += value[graph[v][0]][1]


struct Data{
    int sheep;
    int wolf;
    int index;
    
    Data(int sheep, int wolf, int index) : sheep(sheep), wolf(wolf), index(index) {}
};

struct cmp{
    bool operator()(Data a, Data b)
    {
        if (a.sheep != b.sheep)
            return a.sheep < b.sheep;
        else
            return a.wolf > b.wolf;
    }
};
int solution(vector<int> info, vector<vector<int>> edges) {
    int vertexSize = info.size();
    // cout << vertexSize;
    for (int i = 0 ; i < edges.size() ; ++i){
        //# v-> v1, sheep, wolf
        graph[edges[i][0]].push_back(edges[i][1]);
    for (int i = 0 ; i < vertexSize ; ++i){
        if (info[i])
            value[i].second = 1;
        else
            value[i].first = 1;
    }
}
    
    preorder(0, info, edges);
    for (int j = 0 ; j < vertexSize ; ++j){
         cout << value[j].first << ' ' << value[j].second << '\n';
    }
    
    visited[0] = true;
    priority_queue<Data, vector<Data>, cmp> pq;
    sheepCnt++;
    for (int i = 0 ; i < vertexSize - 1 ; ++i)
    {
        for (int j = 0 ; j < vertexSize ; ++j)
        {
            if (!visited[j])
                continue;
            for (int k = 0 ; k < graph[j].size() ; ++k)
            {
                if (visited[graph[j][k]])
                    continue;
                pq.push({sheepCnt + value[graph[j][k]].first, wolfCnt + value[graph[j][k]].second, graph[j][k]});
                
            }
        }
        cout << "\n\n";
        if (sheepCnt<= wolfCnt)
            break;
        while (!pq.empty())
        {
            struct Data tmp = pq.top();
            cout << tmp.sheep <<  ' ' << tmp.wolf << ' ' << tmp.index << '\n';
            pq.pop();
            if (info[tmp.index])
            {
                if (sheepCnt > wolfCnt + 1)
                {
                    visited[tmp.index] = true;
                    wolfCnt++;
                    break;
                }
            }
            else
            {
                if (sheepCnt + 1 > wolfCnt)
                {
                    visited[tmp.index] = true;
                    sheepCnt++;
                    break;
                }    
            }
            
        }
        cout << "Cnt:" << sheepCnt << ' ' << wolfCnt << '\n';
        while (!pq.empty())
            pq.pop();
    }
    
    int answer = sheepCnt;
    return answer;
}
