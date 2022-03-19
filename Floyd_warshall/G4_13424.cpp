#include <bits/stdc++.h>
using namespace std;
int n, m;
int cost[101][101];
#define INF 1e9
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int a, b, c;
        
        for (int i = 1 ; i <= n ; ++i)
        {
            for (int j = 1 ; j <= n ; ++j)
            {
                cost[i][j] = INF;
                if (i == j)
                    cost[i][j] = 0;
            }   
        }
        for (int i = 0 ; i < m ; ++i)
        {
            cin >> a >> b >> c;
            cost[a][b] = c;
            cost[b][a] = c;
        }
        for (int k = 1 ; k <= n ; ++k)
        {
            for (int i = 1 ; i <= n ; ++i)
            {
                for (int j = 1 ; j <= n ; ++j)
                {
                    if (cost[i][k] + cost[k][j] < cost[i][j])
                        cost[i][j] = cost[i][k] + cost[k][j];
                }   
            }
        }
        int friendNum;
        cin >> friendNum;
        vector<int> friends(friendNum);
        for (int i = 0 ; i < friendNum ; ++i)
        {
            cin >> friends[i];
        }
        int maxValue = INF;
        int answer = 1;
        for (int i = 1 ; i <= n ; ++i)
        {
            int sum = 0;
            
            for (int j = 0 ; j < friendNum ; ++j)
            {
                sum += cost[friends[j]][i];
            }
            if (sum < maxValue)
            {
                maxValue = sum;
                answer = i;
            }
        }
        cout << answer << '\n';
    }    
}
