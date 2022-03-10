#include <bits/stdc++.h>
using namespace std;
#define MAX 20
vector<int> v[100001];
int dp[MAX + 1][100001];
bool visited[100001];
int depth[100001];
int n, m, v1, v2;
void DFS(int num, int d)
{
    visited[num] = true;    // num 사용
    depth[num] = d;         // 길이 저장
    for (int i = 0 ; i < v[num].size() ; ++i)
    {
        if (visited[v[num][i]])
            continue;
        dp[0][v[num][i]] = num;
        DFS(v[num][i], d + 1);
    }
}
void setDP()
{
    for (int i = 1 ; i <= MAX ; ++i)
    {
        for (int j = 1 ; j <= n ; ++j)
        {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b]) // a의 깊이가 b의 깊이보다 작다면
        swap(a, b); //  -->a > b 로 변환

    for (int i = MAX ; i >= 0 ; i--)
    {
        if (depth[a] - depth[b] >= (1 << i))
            a = dp[i][a];
    }
    if (a == b) return a;
    
    // 같지 않다면
    for (int i = MAX ; i >= 0 ; i--)
    {
        if (dp[i][a] != dp[i][b]){
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);   
    cin >> n;
    for (int i = 1 ; i < n ; ++i)
    {
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    DFS(1, 1);//깊이 탐색
    setDP();
    
    cin >> m;
    int a, b;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }

}