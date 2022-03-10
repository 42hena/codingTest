//https://www.acmicpc.net/problem/2252
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


vector<int> v[32001];
int inDegree[32001];
int n, m;
int v1, v2, w;

void topologySort()
{
    queue<int> q;

    for (int i = 1 ; i <= n ; ++i)
    {
        if (!inDegree[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        for (int i = 0 ; i < v[tmp].size() ; ++i){
            inDegree[v[tmp][i]]--;
            if (!inDegree[v[tmp][i]])
                q.push(v[tmp][i]);
        }
    }
}


int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0 ; i < m ; ++i){
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        inDegree[v2]++;
    }
    topologySort();
}