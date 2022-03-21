#include <bits/stdc++.h>
using namespace std;

int cost[52][52];
int main()
{
    int n;
    cin >> n;
    char v1, v2;
    string temp;

    const int INF = 150000;
    for (int i = 0; i < 52; ++i)
    {
        for (int j = 0; j < 52; ++j)
        {
            if (i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> v1 >> temp >> v2;
        int start, end;
        if ('a' <= v1 && v1 <= 'z')
            start = v1 - 'a' + 26;
        if ('A' <= v1 && v1 <= 'Z')
            start = v1 - 'A';
        if ('a' <= v2 && v2 <= 'z')
            end = v2 - 'a' + 26;
        if ('A' <= v2 && v2 <= 'Z')
            end = v2 - 'A';
        cost[start][end] = 1;
    }

    for (int k = 0; k < 52; ++k)
    {
        for (int i = 0; i < 52; ++i)
        {
            for (int j = 0; j < 52; ++j)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    vector<pair<char, char>> v;
    for (int i = 0; i < 52; ++i)
    {
        for (int j = 0; j < 52; ++j)
        {
            if (cost[i][j] < INF && cost[i][j] != 0 && i != j)
            {
                char a, b;
                if (i < 26)
                    a = 'A' + i;
                else
                    a = 'a' + i - 26;
                if (j < 26)
                    b = 'A' + j;
                else
                    b = 'a' + j - 26;
                v.push_back({a, b});
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto i : v)
        cout << i.first << " => " << i.second << '\n';
}