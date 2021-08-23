import math
N = int(input())
dp = [100000] * (N + 1)
i = 1
while pow(i, 2) <= N + 1:
    dp[pow(i, 2)] = 1
    i += 1
for i in range(1, N + 1):
    cnt = 1
    while i >= 2 * pow(cnt,2):
        dp[i] = min(dp[i], dp[i-pow(cnt,2)] + dp[pow(cnt,2)])
        cnt += 1
print(dp[N])