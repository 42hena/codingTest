#include <bits/stdc++.h>
using namespace std;
int cache[10001];
int timeValue[10001];
int times[10001];
int visited[10001];
struct Data{
    int v;
};
vector<int> graph[10001];
int main()
{
    int n;
    cin >> n;
    int time, num;
    for (int i = 1 ; i <= n ; ++i)
    {
        cin >> time >> num;
        timeValue[i] = time;
        int anotherV;
        for (int j = 0 ; j < num ; ++j)
        {
            cin >> anotherV;
            graph[anotherV].push_back(i);
        }
        cache[i] = num;
    }

    queue<int> q;
    for (int i = 1 ; i <= n ; ++i)
        if (!cache[i])
        {
            q.push(i);
            times[i] = timeValue[i]; 
            visited[i] = true;
        }

    while (!q.empty())   
    {
        int now = q.front();
        q.pop();
        for (int i = 0 ; i < graph[now].size() ; ++i)
        {
            int next = graph[now][i];
            
            cache[next]--;
            times[next] = max(times[now] + timeValue[next], times[next]);
        }
        for (int i = 1 ; i <= n ; ++i)
            if (!cache[i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; ++i)
        ans = max(ans, times[i]);
    cout << ans;
}