//https://www.acmicpc.net/problem/1167
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int d;
int farNode;
// int cost[100001];
bool visited[100001];
void search(vector<vector<pair<int, int>>> &v, int index, int cost)
{
    if (visited[index])
        return ;
    
    visited[index] = true;
    
    if (d < cost)
    {
        d = cost;
        farNode = index;
    }

    for (int i = 0 ; i < v[index].size() ; ++i)
    {
        search(v,  v[index][i].first, cost + v[index][i].second);   
    }
}

int main(void)
{
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> v(n + 1);
    

    //n - 1개 받아야함(문제 조건)
    for (int i = 0 ; i < n ; ++i){
        //v1: 시작 노드 v2: 끝 노드 weight v1----v2의 가중치
        int nodeNum;
        cin >> nodeNum;
        int v2, weight;
        while (true){
            
            cin >> v2;
            if (v2 == -1)
                break;
            
            cin >> weight;
            v[nodeNum].push_back({v2, weight});
            // cout <<nodeNum <<' ' << v2 <<weight <<'\n';
        }
    }    

    search(v, 1, 0);
    memset(visited, false, sizeof(visited));
    d = 0;
    search(v, farNode, 0);
    cout << d;
}