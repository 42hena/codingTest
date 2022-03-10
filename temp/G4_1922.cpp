//https://www.acmicpc.net/problem/1922
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Data{
    int vertex1, vertex2, weigth;

    Data(int v1, int v2, int w) : vertex1(v1), vertex2(v2), weigth(w)
    {}
    bool operator<(const struct Data &p)const
    {
        return this->weigth > p.weigth;
    }
};

int parent[1000001];
int find_parent(int x)
{
    if (parent[x] == x)     return x;
    else                    return parent[x] = find_parent(parent[x]);
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
    int v1, v2, w;

    cin >> n >> m;

    for (int i = 1 ; i <= n ; ++i)
        parent[i] = i;

    priority_queue<Data> pq;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> v1 >> v2 >> w;
        pq.push({v1, v2, w});
    }

    int sum = 0;
    while (!pq.empty())
    {
        struct Data tmp = pq.top();
        pq.pop();
        if (find_parent(tmp.vertex1) != find_parent(tmp.vertex2))
        {
            union_parent(tmp.vertex1, tmp.vertex2);
            sum += tmp.weigth;
        }
    }
    cout << sum;
}