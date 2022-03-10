//https://www.acmicpc.net/problem/1717
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int parent[1000001];
int find_parent(int x)
{
    return parent[x] == x ? x : parent[x];
}
bool union_parent(int x, int y)
{
    int px = find_parent(x);
    int py = find_parent(y);

    if (px < py)
        parent[py] = px;
    else
        parent[px] = py;
    // cout << px << ' ' << py;
    return px == py ? true : false;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++i)
        parent[i] = i;

    for (int i = 0 ; i < m ; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0)
        {
            union_parent(b, c);
        }
        else{
            if (find_parent(b) == find_parent(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }   
    // cout << endl;
    // for (int i = 1 ; i <= n ; ++i)
    //     cout << parent[i] << ' ';
}