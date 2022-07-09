#include <bits/stdc++.h>
using namespace std;

// [n : 보석의 수]
// [k : 가방의 수]
// [Mi : 보석의 무게]
// [Vi : 보석의 가격]
// [Ci : 최대 무게]

int n, k;
vector<pair<int, int>> jewels;
vector<int> bags;
int main(void)
{
    cin >> n >> k;
    int m, v;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> m >> v;
        jewels.push_back(make_pair(m, v));
    }
    sort(jewels.begin(), jewels.end());

    int c;
    for (int i = 0 ; i < k ; ++i)
    {
        cin >> c;
        bags.push_back(c);
    }
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    long long jewelTotalPrice = 0;
    int index= 0 ;
    for (int i = 0 ; i < k ; ++i)
    {
        while (index < n && jewels[index].first <= bags[i])
        {
            pq.push(jewels[index].second);
            index++;
        }
        if (!pq.empty())
        {
            jewelTotalPrice += pq.top();
            pq.pop();
        }
    }
    cout << jewelTotalPrice;
}