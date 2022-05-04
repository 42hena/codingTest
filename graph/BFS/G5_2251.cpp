#include <bits/stdc++.h>
using namespace std;
#define MAX 201
int a, b, c;

bool visited[MAX][MAX][MAX];

struct Data
{
    int remainA, remainB, remainC;
};

int main()
{
    cin >> a >> b >> c;

    queue<Data> q;
    q.push({0, 0, c});
    vector<int> v;
    while (!q.empty())
    {
        int ra, rb, rc;
        ra = q.front().remainA;
        rb = q.front().remainB;
        rc = q.front().remainC;
        q.pop();

        if (visited[ra][rb][rc])    continue;

        visited[ra][rb][rc] = true;  
        if (ra == 0)        v.push_back(rc);
        // a b
        if (ra + rb > b)    q.push({ra + rb - b, b, rc});
        else                q.push({0, ra + rb, rc});

        //a c
        if (ra + rc > c)    q.push({ra + rc - c, rb, c});
        else                q.push({0, rb, ra + rc});

        //b a
        if (rb + ra > a)    q.push({a, rb + ra - a, rc});
        else                q.push({rb + ra, 0, rc});

        //b c
        if (rb + rc > c)    q.push({ra, rb + rc - c, c});
        else                q.push({ra, 0, rb + rc});

        //c a
        if (rc + ra > a)    q.push({a, rb, rc + ra - a});
        else                q.push({rc + ra, rb, 0});

        //c b
        if (rc + rb > b)    q.push({ra, b, rc + rb - b});
        else                q.push({ra, rb + rc, 0});
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < v.size() ; ++i)
        cout << v[i] << ' ';
}