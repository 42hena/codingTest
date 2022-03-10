//https://www.acmicpc.net/problem/10828
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



// void preorder(pair<int, int> p)
// {
//     cout << p
//     preorder(p[p.first])
//     preorder(p[p.second])
// }

// void inorder(pair<int, int> p)
// {
    
// }

// void postorder(pair<int, int> p)
// {
    
// }

pair<int, int> edge[26];
int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        char a, b, c;
        cin >> a >> b >> c;
        if (b != '.')   edge[a - 'A'].first = b - 'A';
        else            edge[a - 'A'].first = '.';
        if (c != '.')   edge[a - 'A'].second = c - 'A';
        else            edge[a - 'A'].second = '.';
    }

    for (int i = 0 ; i < 26 ; ++i)
    {
        printf("%d %d\n", edge[i].first, edge[i].second);
    }

    // preorder(edge[0]);
    // cout <<endl;
    // inorder(p);
    // cout <<endl;
    // postorder(p);
}