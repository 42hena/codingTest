#include <bits/stdc++.h>
using namespace std;

int cost[26][26];
#define INF 1e9
int main()
{

    int n, m;
    cin >> n;
    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }

    char v1, v2;
    string is;
    for (int i = 0; i < n; ++i)
    {
        cin >> v1 >> is >> v2;
        cost[v1 - 'a'][v2 - 'a'] = 1;
    }
    for (int k = 0; k < 26; ++k)
    {
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> v1 >> is >> v2;
        if (cost[v1 - 'a'][v2 - 'a'] != INF)
            cout << "T\n";
        else
            cout << "F\n";
    }
    
}