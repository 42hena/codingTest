#include <bits/stdc++.h>
using namespace std;
struct Data
{
    int day;
    int money;
};
int cache[15];
int main()
{
    int n;
    cin >> n;
    vector<Data> v(n);
    for (int i = 0 ; i < n ; ++i)   
    {
        cin >> v[i].day >> v[i].money;
    }
    cache[0] = v[0].money;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < i ; ++j)
        {
            cache[i] = max(cache[i], v[j].money + v[i].money);
        }
    }
    
    for (int i = 0 ; i < n ; ++i)   
        cout << cache[i] << ' ';
}