N = int(input())
dp = [0] * (N + 1)
dp[0] = 1
if N > 0:
    dp[1] = 2
if N > 1:
    dp[2] = 7
for i in range(3, N + 1):
    dp[i] = 2 * dp[i - 1] + dp[i - 2] + 6 * dp[i - 3]
    dp[i] %= 1000000007
print(dp[N])