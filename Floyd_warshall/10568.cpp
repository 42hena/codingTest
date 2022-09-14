#include <bits/stdc++.h>
using namespace std;
#define MAX 101

double cost[MAX][MAX];

struct Data
{
    string name;
    long double x, y, z;
};

int main()
{
    cin.tie(0);
    cout.tie(0);
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; ++c)
    {
        int n;
        cin >> n;

        for (int i = 0 ; i < n; ++i)
        {
            for (int j = 0 ; j < n; ++j)
            {
                cost[i][j] = 1e9;
                if (i == j)
                    cost[i][j] = 0;
            }
        }

        vector<Data> v;
        map<string, int> info;
        for (int i = 0; i < n; ++i)
        {
            string name;
            long double x, y, z;

            cin >> name >> x >> y >> z;
            info[name] = i;
            v.push_back({name, x, y, z});
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0 ; j < n; ++j)
            {
                long double value = sqrt(
                (v[i].x - v[j].x)*(v[i].x - v[j].x) + 
                (v[i].y - v[j].y)*(v[i].y - v[j].y) + 
                (v[i].z - v[j].z)*(v[i].z - v[j].z)
                );
                cost[i][j] = value;
            }
        }

        int w;
        cin >> w;
        for (int i = 0; i < w; ++i)
        {
            string prev, next;
            cin >> prev >> next;

            int s = info[prev];
            int t = info[next];
            
            cost[s][t] = 0.0;
        }

        for (int via = 0; via < n; ++via)
        {
            for (int start = 0; start < n; ++start)
            {
                for (int end = 0; end < n; ++end)
                {
                    cost[start][end] = min(cost[start][end], cost[start][via] + cost[via][end]);
                }
            }
        }

        int q;
        cin >> q;
        cout << "Case " << c + 1 << ":\n";
        for (int i = 0; i < q; ++i)
        {
            string q1, q2;
            cin >> q1 >> q2;

            auto iter = info.find(q1);
            int s = info[q1];
            int t = info[q2];
            cout << "The distance from " << q1 << " to " << q2 << " is " << fixed << setprecision(0) << round(cost[s][t]) << " parsecs.\n";
        }
    }
}