#include <bits/stdc++.h>
using namespace std;
struct Data{
    int v, w;
};
vector<Data> graph[100001];

int dist[100001];
bool visited[100001];

int n;
void test(int start)
{
    // cout <<"start" <<  start << '\n';
    for (int i = 0 ; i < graph[start].size() ; ++i)
    {
        int next = graph[start][i].v;
        int nextCost = graph[start][i].w;
        
        if (!visited[next])
        {
            if (dist[next] < dist[start] + nextCost)
                dist[next] = dist[start] + nextCost;
            // cout << "next" << next << '\n';
            visited[next] = true;
            test(next);
            visited[next] = false;
        }
    }
}

int main()
{
    cin >> n;
    int num, v2, w, m;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> num;
        while (true)
        {
            cin >> v2;
            if (v2 == -1)
                break;
            cin >> w;
            graph[num].push_back({v2, w});        
        }
    }
    dist[1] = 0;
    visited[1]=true;
    test(1);
    int maxIndex = 1;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (dist[maxIndex] < dist[i])
            maxIndex = i;
    }
    // cout << maxIndex;
    for (int i = 1 ; i <= n ; ++i)
    {
        dist[i] = 0;
        visited[i] = false;
    }
    visited[maxIndex] = true;
    test(maxIndex);
    int maxValue = 0;
    for (int i = 1 ; i <= n ; ++i)
    {
        maxValue = max(maxValue, dist[i]);
    }
    cout << maxValue;
}