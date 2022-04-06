#include <bits/stdc++.h>
using namespace std;

int stair[300];
int cache[300];

int recursive(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return cache[0] = stair[0];
    if (n == 1)
        return cache[1] = stair[1] + stair[0];
    int &ret = cache[n];
    if (ret != -1)
        return ret;   
    ret = stair[n]; 
    return ret += max(stair[n - 1] + recursive(n - 3), recursive(n - 2));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> stair[i];
    }
    memset(cache, -1, sizeof(cache));
    cout << recursive(n - 1);
}