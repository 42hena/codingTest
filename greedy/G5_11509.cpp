#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    int maxValue = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        int now = v[i];
        auto iter = m.find(now);
        if (iter == m.end())
        {
            if (now - 1 > 0)
            {
                auto itertmp = m.find(now - 1);
                if (itertmp == m.end())
                    m.insert({now - 1, 1});
                else
                    m[now - 1] += 1;
            }
            maxValue++;
        }
        else
        {
            m[now] -= 1;
            if (m[now] == 0)
                m.erase(iter);
            if (now - 1 > 0)
            {
                auto itertmp = m.find(now - 1);
                if (itertmp == m.end())
                    m.insert({now - 1, 1});
                else
                    m[now - 1] += 1;
            }
        }
    }
    cout << maxValue;
}