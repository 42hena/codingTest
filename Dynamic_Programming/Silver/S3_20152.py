H, N = map(int, input().split())
N = abs(H - N) + 1
# print(N)
dp = [[0] * (N + 1) for _ in range(N + 1)]

dp[1][1] = 1

for i in range(2, N + 1):
    for j in range(1, i + 1):
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j]
print(dp[N][N])

# for i in range(N + 1):
#     for j in range(i + 1):
#         print(dp[i][j], end="")
#     print()
