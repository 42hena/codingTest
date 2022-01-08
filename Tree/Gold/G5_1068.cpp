//https://www.acmicpc.net/problem/1068
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int ans;
bool removearr[50];

void search(vector<vector<int>> v, int index)
{
    // cout << index;
    
    if (!v[index].size()){
        ans++;
        return ;
    }
        
    int cnt = 0;
    for (auto iter = v[index].begin() ; iter!= v[index].end() ; iter++)
    {
        if (removearr[*iter] == false){
            cnt++;
        }
    }
    // cout << " cnt, index " << cnt  << ' ' << index<< '\n';
    if (cnt == 0)
    {
        ans++;
        return ;
    }
    
    
    for (auto iter = v[index].begin() ; iter!= v[index].end() ; iter++)
    {
        
        if (removearr[*iter] == false){
            // cout << *iter;
            search(v, *iter);
        }
    }
    return ;   
}

int main(void)
{
    // cin.tie(0);
    // cout.tie(0);
    // ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(50, 0);
    vector<vector<int>> v(50);

    int root;
    for (int i = 0 ; i < n ; ++i){
        cin >> a[i];
        if (a[i] == -1)
            root = i;
    }
    // sort(a.begin(), a.end());
    int cnt = 0;
    for (int i = 0 ; i < n  ; i++)
    {
        int num = a[i];
        if (a[i] == -1){
            continue;
        }
        else
        {
            v[num].push_back(i);
        }
    }

    int m;
    cin >> m;
    removearr[m] = true;


    if (m != root)
        search(v, root);
    cout << ans;
}