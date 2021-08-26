n, m = map(int, input().split())

dp = [[0]*(n+2) for _ in range(n+2)]
dp[1][1] = 1

for i in range(2, n + 2):
    for j in range(i+1):
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
print(dp[n+1][m+1])