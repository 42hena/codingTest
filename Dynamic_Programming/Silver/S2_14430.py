N, M = map(int, input().split())

dp = []
for i in range(N):
    dp.append(list(map(int, input().split())))
# print(dp)

for i in range(N):
    for j in range(M):
        if i - 1 >= 0 and j - 1 >= 0:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dp[i][j]
        elif i - 1 >= 0:
            dp[i][j] = dp[i-1][j] + dp[i][j]
        elif j - 1 >= 0:
            dp[i][j] = dp[i][j-1] + dp[i][j]
print(dp[N-1][M-1])