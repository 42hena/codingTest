#include <bits/stdc++.h>
using namespace std;

long long memo[91];
int main()
{
    int n;

    cin >> n;
    memo[1] = 1;
    for (int i = 2 ; i <= n ; ++i)
        memo[i] = memo[i - 1] + memo[i - 2];
    cout << memo[n];
}