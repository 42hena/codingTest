#include <bits/stdc++.h>
using namespace std;
int graph[100001];
bool visited[100001];
bool ans[100001];
int n;
int cnt;
void depth_first_search(int now)
{
    visited[now] = true;
    int next = graph[now];
    if (!visited[next])
        depth_first_search(next);
    else if (!ans[next])
    {
        for (int i = next; i != now; i = graph[i]) {
			cnt++;
		}
		cnt++;
    }
    ans[now] = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    for (int Case = 0 ; Case < t ; ++Case)
    {
        
        
        cin >> n;
        int num;
        for (int i = 0 ; i < n ; ++i)
            cin >> graph[i + 1];

        for (int i = 0 ; i < n ; ++i)
        {
            if (visited[i + 1])
                continue;
            depth_first_search(i + 1);
        }
        cout << n - cnt << '\n';
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(ans, 0, sizeof(ans));
    }
}