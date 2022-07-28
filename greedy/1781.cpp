#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


struct Data
{
    int day;
    int ramenNum;
    bool operator<(const Data &c)   const
    {
        if (day == c.day)
            return ramenNum > c.ramenNum;
        return day < c.day;
    }
};

struct schedule
{
    int day;
    int ramenNum;
    bool operator<(const schedule &c)   const
    {
        if (ramenNum == c.ramenNum)
            return day < c.day;
        return ramenNum < c.ramenNum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    priority_queue<Data> ramen;

    int maxDay = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        int deadLine, ramenNum;
        cin >> deadLine >> ramenNum;
        ramen.push({deadLine, ramenNum});
        if (maxDay < deadLine)
            maxDay = deadLine;
    }
    // pq.push({deadLine, ramen});
    // while (!pq.empty())
    // {
    //     cout << pq.top().day << ' ' << pq.top().ramenNum << '\n';
    //     pq.pop();0
    // }
    // for (auto x: v)
    // {
    //     cout << x.day << ' ' << x.remenNum << '\n';
    // }

    priority_queue<schedule> pq;
    long long total = 0;
    for (int i = maxDay ; i > 0 ; --i)
    {
        // cout << "now day" << i << '\n';
        // cout << "before ramen size: [" << ramen.size() << "]\n";
        while(!ramen.empty())
        {
            Data tmp = ramen.top();
            if (tmp.day < i)
                break;
            pq.push({tmp.day, tmp.ramenNum});
            ramen.pop();
        }
        // cout << "After ramen size: [" << ramen.size() << "]\n";
        
        if (!pq.empty())
        {
            total += pq.top().ramenNum;
            pq.pop();
        }
    }
    cout << total;
}