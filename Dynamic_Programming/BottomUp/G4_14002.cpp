#include <bits/stdc++.h>
using namespace std;
int cache[1000][2];
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> v[i];
    }
    memset(cache, -1, sizeof(cache));
    for (int i = 0 ; i < n ; ++i)
    {
        cache[i][0] = 1;
        for (int j = 0 ; j < i ; ++j)
        {
            if (v[j] < v[i] && cache[j][0] + 1 > cache[i][0])
            {
                cache[i][0] = cache[j][0] + 1;
                cache[i][1] = j;
            }
        }
    }
    int maxIndex = 0;
    for (int i = 0 ; i < n ; ++i)
    {
        if (cache[maxIndex][0] < cache[i][0])
            maxIndex = i;
    }
    cout << cache[maxIndex][0] << '\n';
    
    vector<int> ans;
    
    while (maxIndex != -1)
    {
        ans.push_back(v[maxIndex]);
        maxIndex = cache[maxIndex][1];
    }
    
    reverse(ans.begin(), ans.end());
    for (int i = 0 ; i < ans.size() ; ++i)
        cout << ans[i] << ' ';
}