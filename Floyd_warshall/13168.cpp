#include <bits/stdc++.h>
using namespace std;

#define MAX 101
int n, r;
float cost1[MAX][MAX];
float cost2[MAX][MAX];
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

int main()
{
    cin >> n >> r;
    map<string, int> city;
    string tmp;
    for (int i = 0 ;i < n  ;++i)
    {
        cin >> tmp;
        city.insert({tmp, i + 1});
    }
    int m;
    cin >> m;
    vector<int> travel;
    for (int i = 0 ; i < m ; ++i)
    {
        cin >> tmp;
        auto iter = city.find(tmp);
        int val = iter->second;
        // cout << val << ' ';
        travel.push_back(val);
    }

    for (int i = 1 ; i < n + 1 ; ++i)
        for (int j = 1 ; j < n + 1 ; ++j)
        {
            cost1[i][j] = 1e9;
            cost2[i][j] = 1e9;
            if (i == j)
            {
                cost1[i][j] = 0;
                cost2[i][j] = 0;
            }
        }
    
    int K;
    cin >> K;
    for (int i = 0 ; i < K ; ++i)
    {
        string a, b, c;
        float cost;
        cin >>  a >> b >> c >> cost;
        int s = city.find(b)->second;
        int e = city.find(c)->second;
        if (a == "Mugunghwa" || a == "ITX-Saemaeul" || a == "ITX-Cheongchun")
        {
            cost2[s][e] = 0;
            cost2[e][s] = 0;
        }
        if (a == "S-Train" || a == "V-Train")
        {
            cost2[s][e] = min(cost2[s][e], (float)cost / 2);
            cost2[e][s] = min(cost2[s][e], (float)cost / 2);
        }
        cost1[s][e] = min(cost1[s][e], cost); 
        cost1[e][s] = min(cost1[s][e], cost); 
        cost2[s][e] = min(cost2[s][e], cost); 
        cost2[e][s] = min(cost2[s][e], cost); 
    }
    
    for (int k = 1 ; k < n + 1 ; ++k)
    {
        for (int i = 1 ; i < n + 1 ; ++i)
            for (int j = 1 ; j < n + 1 ; ++j)
            {
                cost1[i][j] = min(cost1[i][j], cost1[i][k] + cost1[k][j]);
                cost2[i][j] = min(cost2[i][j], cost2[i][k] + cost2[k][j]);
            }
    }

    float total1 = 0;
    float total2 = 0;
    for (int i = 0 ; i < travel.size() - 1 ; ++i)
    {
        int s = travel[i];
        int e = travel[i + 1];
        total1 += cost1[s][e];
        total2 += cost2[s][e];
    }
    total2 += r;
    if (total1 > total2)
        cout << "Yes";
    else
        cout << "No";
    
}