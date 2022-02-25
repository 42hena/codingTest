#include <bits/stdc++.h>

using namespace std;

struct Jewels
{
    int weight;
    int price;
    Jewels(int weight, int price) : weight(weight), price(price)
    {

    }
    bool operator<(const struct Jewels &copy) const
    {
        if (weight == copy.weight)
            return price < copy.price;
        else
            return weight > copy.weight;
    }
};
int n, k;
int m, v;
int c;
int main()
{
    cin >> n >> k;
    vector<pair<int, int>> jewel;
    
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> m >> v;
        jewel.push_back({m, v});
    }
    sort(jewel.begin(), jewel.end());

    vector<int> bag;
    for (int i = 0 ; i < k ; ++i)
    {
        cin >> c;
        bag.push_back(c);
    }
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    int index = 0;
    long long ans = 0;
    for (int i = 0 ; i < k ; ++i)
    {
        while (index < n && jewel[index].first <= bag[i])
        {
            pq.push(jewel[index].second);
            index++;
        }
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}