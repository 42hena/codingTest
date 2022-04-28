#include <bits/stdc++.h>
using namespace std;
#define MAX 101
long long cost[MAX][MAX];
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, p, q;
        cin >> n >> p >> q;// 사람 수, 은하 수, 은하간 길이 개수

        vector<int> people(n);
        for (int i = 0 ; i < n ; ++i)
            cin >> people[i];
        
        int v1, v2;
        long long w;
        for (int i = 1 ; i < p + 1 ; ++i)
        {
            for (int j = 1 ; j < p + 1 ; ++j)
            {
                cost[i][j] = 1e10;
                if (i == j)
                    cost[i][j] = 0;
            }
        }

        for (int i = 0 ; i < q ; ++i)
        {
            cin >> v1 >> v2 >> w;
            cost[v1][v2] = min(w, cost[v1][v2]);
            cost[v2][v1] = min(w, cost[v2][v1]);
        }

        for (int k = 1 ; k < p + 1 ; ++k)
        {
            for (int i = 1 ; i < p + 1 ; ++i)
            {
                if (cost[i][k] == (int)1e10) continue;
                for (int j = 1 ; j < p + 1 ; ++j)
                {
                    if (cost[k][j] == (int)1e10) continue;
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    

        int minIndex = 0;
        long long minValue = 1e10;
        // cout << "test\n";
        for (int k = 1 ; k < p + 1 ; ++k)
        {   
            unsigned long long sum = 0;
            
            for (int i = 0 ; i < n ; ++i)
            {
                int now = people[i];
                sum += cost[now][k] * cost[now][k];
            }
            if (minValue > sum)
            {
                minValue = sum;
                minIndex = k;
            }
        }
        cout << minIndex << ' ' << minValue << '\n';
    }
}