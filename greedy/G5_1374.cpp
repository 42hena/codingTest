#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int index, s, e;
    bool operator<(const Data &copy)
    {
        if (s != copy.s)
            return s < copy.s;
        return e < copy.e;
    }
};
int main()
{
    int n;
    cin >> n;
    
    
    int maxClassCount = 0;
    vector<Data> v;
    for (int i = 0 ; i < n ; ++i)
    {
        int num, s, e;
        cin >> num >> s >> e;
        v.push_back({num, s, e});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0 ; i < n ; ++i)
    {
        
        if (pq.empty())
        {
            pq.push(v[i].e);
            if (maxClassCount < pq.size())
                maxClassCount = pq.size();
        }
        else
        {
            // cout << pq.top() << '\n';
            if (v[i].s >= pq.top())
            {
                pq.pop();
                pq.push(v[i].e);
            }
            else
            {
                pq.push(v[i].e);
                if (maxClassCount < pq.size())
                    maxClassCount = pq.size();
            }
        }
        // cout << maxClassCount << '\n';
    }
    cout << maxClassCount;
}