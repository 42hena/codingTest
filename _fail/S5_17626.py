from math import sqrt
N = int(input())


dp = [10000] * (N + 1)
dp[1] = 1

for i in range(2, N + 1):
    if pow(int(sqrt(i)), 2) == i:
        dp[i] = 1
        continue
    for j in range(1, (i + 1) // 2 + 1):
        dp[i] = min(dp[i-j] + dp[j], dp[i])
print(dp[N])