#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n;
int cost[51][51];
int friends[51];
int main()
{
    cin >> n;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
        {
            cost[i][j] = INF;
            if (i == j)
                cost[i][j] = 0;
        }

    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == b && a == -1)
            break;
        cost[a][b] = 1;
        cost[b][a] = 1;
    }    

    for (int k = 1 ; k <= n ; ++k)
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    
    
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= n ; ++j)
        {
            friends[i] = max(friends[i], cost[i][j]);
        }
    }
    int minValue = INF;
    for (int i = 1 ; i <= n ; ++i)
    {
        minValue = min(friends[i], minValue);
    }
    vector<int> v;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (minValue == friends[i])
            v.push_back(i);
    }
    cout << minValue << ' ' << v.size() << '\n';
    for (auto value : v)
        cout << value << ' ';
}