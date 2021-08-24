N = int(input())
#1, 2, 5, 7
coin = [1, 2, 5, 7]

dp = [100000] * (N + 1)
dp[0] = 0
if N > 0:
    dp[1] = 1
for i in range(4):
    for j in range(coin[i], N + 1):
        dp[j] = min(dp[j], dp[j - coin[i]] + 1)
print(dp[N])