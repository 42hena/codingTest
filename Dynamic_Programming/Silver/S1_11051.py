N, K = map(int, input().split())

dp = [[0] * (N + 2) for _ in range(N + 2)]
dp[1][1] = 1

for i in range(2, N + 2):
    for j in range(i + 1):
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
        dp[i][j] %= 10007
print(dp[N + 1][K + 1])