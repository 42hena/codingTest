n = int(input())

dp = [0] * (n + 1)
dp[0] = 1
for i in range(1, n + 1):
    tmp = 0
    for j in range(i):
        tmp += dp [i - j - 1] * dp[j]
    dp[i] = tmp
print(dp[n])