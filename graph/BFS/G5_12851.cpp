#include <bits/stdc++.h>
using namespace std;
int n, m;
int visited[100001];
int main()
{
    cin >> n >> m;
    fill(visited,visited + 100001 ,-1 );
    visited[n] = 0;
    queue<pair<int, int>> q;
    q.push({n, 0});
    int ans = 100000;
    int count = 0;
    while (!q.empty())
    {
        int now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt > ans)
            continue;
        if (now == m)
        {
            ans = cnt;
            count++;
            continue;
        }
        cout << now << ' ' << cnt << '\n';
        if (now - 1 >= 0 && (visited[now - 1] == -1 || cnt < visited[now - 1]))
        {
            visited[now - 1] = cnt + 1;
            q.push({now - 1, cnt + 1});
        }
        if (now + 1 <= 100000 && (visited[now + 1] == -1 || cnt < visited[now + 1]))
        {
            visited[now + 1] = cnt + 1;
            q.push({now + 1, cnt + 1});
        }
        if (now * 2 <= 100000 && (visited[now * 2] == -1 || cnt < visited[now * 2]))
        {
            visited[now * 2] = cnt + 1;
            q.push({now * 2, cnt + 1});
        }
            
    }
    cout << ans <<'\n';
    cout << count;
}