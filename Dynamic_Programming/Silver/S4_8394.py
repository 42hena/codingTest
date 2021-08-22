n = int(input())

dp = [0] * 60
dp[0] = 1
dp[1] = 1

for i in range(2, 60):
    dp[i] = (dp[i - 1] + dp[i - 2])%10

print(dp[n%60])