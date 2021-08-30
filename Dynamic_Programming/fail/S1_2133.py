N = int(input())

dp = [0] * (31)
dp[2] = 3

for i in range(4, 31):
    if dp[i - 2] == 0:
        continue
    else:
        dp[i] = 3 * dp[i - 2] + 2
print(dp[N])
