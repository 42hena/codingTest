#S5 Four Squares
N = int(input())

dp = [10000] * (N + 1)
dp[0] = 0
dp[1] = 1


for i in range(2, N + 1):
    if dp[i] == 1:
        continue

    j = 1
    while j ** 2 <= i:
        dp[i] = min(dp[i], dp[i - j**2] + 1)
        j += 1

print(dp[N])