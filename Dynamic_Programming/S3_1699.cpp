// link: https://www.acmicpc.net/problem/1699
// type: dynamic programming
// level: silver 3

#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int main()
{
    // 구하려는 자연수 N, N이 11이라면 3^2 + 1^2 + 1^2으로 가능해서 3이 된다.
	int n;
    
	cin >> n;

    // dp 테이블 초기화
	memset(dp, 127, sizeof(dp));
	
    // 0번 째 값은 0으로 초기화
    dp[0] = 0;
	for (int i = 1 ; i < n + 1 ; ++i)
	{
        // root값을 int화 한 후 제곱이 i값이랑 같으면  제곱수 이므로 dp값을 1로 초기화
		double tmp = pow(i, 1 / 2.0);
		if (i == (int)tmp *(int) tmp)
		{
			dp[i] = 1;
			continue;
		}
        // 모든 경우를 다 볼 경우 100000 * 50000 이라서 50억의 연산이므로 50초가 필요 (fail)
        // 따라서 제곱씩 늘어나면 몇 가지 경우만 볼 수 있다.
		for (int j = 1 ; j * j < i ; ++j)
		{
			dp[i] = min(dp[i], dp[j * j] + dp[i - j*j]);
		}
	}
	cout << dp[n];
}