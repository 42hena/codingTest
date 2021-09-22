m, n = map(int, input().split())
dp = [[0]*m for _ in range(n)]
dp[0][0] = 1

for i in range(n):
    for j in range(m):
        if j - 1 >= 0:
            dp[i][j] += dp[i][j-1]
        if i - 1 >= 0 and j - 1 >= 0:
            dp[i][j] += dp[i-1][j-1]
        if i - 1 >= 0:
            dp[i][j] += dp[i-1][j]
        dp[i][j] %= 1000000007
print(dp[n-1][m-1])