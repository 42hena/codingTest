#include <bits/stdc++.h>
using namespace std;

int needTimes[1001];
int prerequisites[1001];
int cost[1001];
vector<int> build[1001]; 
queue<int> q;
int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        memset(needTimes, 0, sizeof(needTimes));
        memset(prerequisites, 0, sizeof(prerequisites));
        memset(cost, 0, sizeof(cost));
        for (int i = 1 ; i <= n ; ++i)
        {
            build[i].clear();
            cin >> needTimes[i];
        }
        int v1, v2;
        for (int i = 1 ; i <= k ; ++i)
        {
            
            cin >> v1 >> v2;
            build[v1].push_back(v2);
            prerequisites[v2]++;
        }
        for (int i = 1 ; i <= n ; ++i)
        {
            if (!prerequisites[i])
            {
                cost[i] = needTimes[i];
                q.push(i);
            }
        }
        int winNumber;
        cin >> winNumber;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            if (now == winNumber)
                break;
            for (int i = 0 ; i < build[now].size() ; ++i)
            {
                int next = build[now][i];
                prerequisites[next]--;
                cost[next] = max(cost[next], cost[now] + needTimes[next]);
                if (!prerequisites[next])
                {
                    
                    q.push(next);
                }
            }
        }
        cout << cost[winNumber] << '\n';
        queue<int> tmpq;
        q.swap(tmpq);
    }
}