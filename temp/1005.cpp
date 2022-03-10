//https://www.acmicpc.net/problem/1005

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int times[1001];
int state[1001];
int ans[1001];
vector<int> v[1001];
int t;
int n, k;
int d;
void topologySort()
{
    queue<int> q;

    for (int i = 1 ; i <= n ; ++i){ // 0이면 바로 들어갈 수 있음
        if (!state[i]){
            q.push(i);
            ans[i] = times[i];
        }
    }
    
    

    int cnt = 0;                    // 카운팅 변수
    
    while (!q.empty())              //q가 빌때까지 함
    {
        int tmp = q.front();
        q.pop();
        
        cout << "tmp : " << tmp << ' ';
        for (int j = 0 ; j < v[tmp].size() ; ++j)
        {
            state[v[tmp][j]]--;
            if (!state[v[tmp][j]])
            {
                q.push(v[tmp][j]);
            }
            ans[v[tmp][j]] = max(ans[v[tmp][j]], times[v[tmp][j]] + ans[tmp]);
        }
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--){
        
        memset(times, 0, sizeof(times));
        memset(state, 0, sizeof(state));
        memset(ans, 0, sizeof(ans));
        cin >> n >> k;
        for (int i = 1 ; i <= n ; ++i)
            v[i].clear();
        for (int i = 1 ; i <= n ; ++i){
            cin >> d;
            times[i] = d; 
        }

        int v1, v2;
        
        for (int i = 1 ; i <= k ; ++i){
            cin >> v1 >> v2;
            v[v1].push_back(v2);
            state[v2]++;
        }    
        topologySort();
        int w;
        cin >> w;
        cout << ans[w] << endl;
    }   
}