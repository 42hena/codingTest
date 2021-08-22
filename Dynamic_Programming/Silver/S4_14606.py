N = int(input())

dp = [0] * (N + 1)
dp[1] = 0

for i in range(2, N + 1):
    dp[i] = dp[i // 2] + dp[i - i // 2] + (i // 2) * (i - i // 2)
print(dp[N])