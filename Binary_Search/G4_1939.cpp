#include <bits/stdc++.h>
using namespace std;

struct Data{
    int v, w;
    bool operator<(const struct Data &copy)const
    {
        return w < copy.w;
    }
};
vector<Data> graph[10001];
bool visited[10001];
int main()
{
    int n, m;
    int l = 1, r = 0;
    cin >> n >> m;
    int v1, v2, w;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        graph[v1].push_back({v2, w});
        graph[v2].push_back({v1, w});
        r = max(r, w);
    }
    int start, end;
    cin >> start >> end;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        cout << "mid" << m <<'\n';
        queue<Data> q;
        q.push({start, 0});
        int initValue = 1000000001;
        for (int i = 1 ; i <= n ; ++i)
            visited[i] = false;
        visited[start] = true;
        bool flag = false;
        while (!q.empty())
        {
            int now = q.front().v;
            int nowCost = q.front().w;
            cout << now << ' ' << nowCost <<'\n';
            q.pop();
            if (now == end)
            {
                flag = true;
            }
            for (int i = 0 ; i < graph[now].size() ; ++i)
            {
                int next = graph[now][i].v;
                int nextCost = graph[now][i].w;
                if (!visited[next] && nextCost >= m)
                {
                    
                    visited[next] = true;
                    q.push({next, nextCost});
                }
            }
        }
        cout << "init" << initValue << '\n';
        if (flag)
        {
            ans = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    cout << ans;
}