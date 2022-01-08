//https://www.acmicpc.net/problem/1967
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int ans = 0;
int search(vector<vector<pair<int, int>>> &v, int index)//return max값
{
    int ret = -1;
    if (v[index].size() == 0) // node가 0개 일때 최댓값 0
    {
        // cout << "s0 index:" << index << "ans"<< ans << '\n';
        return 0;
    }
    if (v[index].size() == 1){ // node가 1개 일때 최댓값 node 가중치 + 아래에서 올라온 최댓값
        ret = v[index][0].second + search(v,  v[index][0].first);
        if (ret > ans){
            
            ans = ret;
            // cout << "s1 index:" << index << "ans"<< ans << '\n';
        }
        return ret;
    }
    
    // node가 2개 이상 일때 node 가중치 + 아래에서 올라온 최댓값 중 2개 합한 값
    int m1 = v[index][0].second + search(v,  v[index][0].first);
    int m2 = v[index][1].second + search(v,  v[index][1].first);
    int tmp;
    if (m1 < m2)
    {
        tmp = m1;
        m1 = m2;
        m2 = tmp;
    }
    for (int i = 2 ; i < v[index].size() ; ++i)
    {
        tmp = v[index][i].second + search(v,  v[index][i].first);
        if (m1 < tmp)//tmp가 제일 클때
        {
            m2 = m1;
            m1 = tmp;
        }
        else if (tmp > m2){
            m2 = tmp;
        }
    }// max1 max2를 구해야함
    if (m1 + m2 > ans)
        ans = m1 + m2;
    // cout << "s2> index:" << index << "ans"<< ans << '\n';
    return m1;
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
    for (int i = 0 ; i < n - 1 ; ++i){
        //v1: 시작 노드 v2: 끝 노드 weight v1----v2의 가중치
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        // cout <<v1 << v2 <<weight <<'\n';
        v[v1].push_back({v2, weight});
    }    

    search(v, 1);   //1번 정점에서 출발
    cout << ans;
}