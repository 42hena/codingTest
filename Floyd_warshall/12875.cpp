#include <bits/stdc++.h>
using namespace std;

int cost[50][50];

int main()
{
    int n;
    int d;
    cin >> n >> d;
    string tmp;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> tmp;
        for (int j = 0 ; j < tmp.size() ; ++j)
        {
            cost[i][j] = 1e9;
            if (tmp[j] == 'Y')
                cost[i][j] = 1;
            if (i == j)
                cost[i][j] = 0;
        }
        
    }
    for (int k = 0 ; k < n ; ++k)
    {
        for (int i = 0 ; i < n ; ++i)
        {
            for (int j = 0 ; j < tmp.size() ; ++j)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    int maxValue = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < tmp.size() ; ++j)
        {
            maxValue = max(maxValue, cost[i][j]);
        }
    }
    if (maxValue == 1e9)
        cout << -1;
    else
        cout << maxValue * d;   
}