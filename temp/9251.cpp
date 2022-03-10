#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
#define FOR(I, N) for(int I = 1 ; I <= N ; ++I)
int main()
{
    string a, b;
    cin >> a >> b;
    int size1 = a.size();
    int size2 = b.size();
    FOR(i, size1)
        FOR(j, size2){
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    cout << dp[size1][size2];
            
}