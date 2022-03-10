//https://www.acmicpc.net/problem/14567
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n, m;

int state[1001];
int ans[1001];

vector<int> v[1001];
void topologySort()
{
    queue<int> q;

    for (int i = 1 ; i <= n ; ++i) // 0이면 바로 들어갈 수 있음
        if (!state[i])
            q.push(i);
    
    int cnt = 0;                    // 카운팅 변수
    
    while (!q.empty())              //q가 빌때까지 함
    {
        cnt++;
        int size = q.size();
        for (int i = 0 ; i < size ; ++i) // size만큼 돌꺼임
        {
            int tmp = q.front();
            q.pop();
            ans[tmp] = cnt;
            
            for (int j = 0 ; j < v[tmp].size() ; ++j)
            {
                state[v[tmp][j]]--;
                if (!state[v[tmp][j]])
                    q.push(v[tmp][j]);       
            }
        }
    }
}



int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    int v1, v2;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2;
        state[v2]++;
        v[v1].push_back(v2);
    }

    // for (int i = 1 ; i <=n ; ++i)
    // {
    //     for (int j = 0 ; j < v[i].size() ; ++j)
    //     {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    topologySort();
    for (int i = 1 ; i <=n ; ++i)
    {
        cout << ans[i] << ' ';
    }
}