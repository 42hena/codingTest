#include <bits/stdc++.h>
using namespace std;

int cache[2][100001];
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; ++i)
        cin >> v[i];
    int ans = 0;
    
    cache[0][0] = v[0];
    cache[1][0] = v[0];
    ans = max(cache[0][0], cache[1][0]);
	for (int i = 1; i < n; i++)
	{
		cache[0][i] = max(0, cache[0][i - 1]) + v[i];
		cache[1][i] = max(cache[1][i - 1] + v[i], cache[0][i - 1]);
		ans = max(max(cache[0][i], cache[1][i]), ans);
	}
    cout << ans;
}