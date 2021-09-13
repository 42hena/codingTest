N, K = map(int, input().split())

dp = [[0] * (K + 1) for _ in range(N + 1)]
#[N][K]

# print(dp)

def sumf(col,row):
    ans = 0
    for i in range(col + 1):
        ans += dp[i][row - 1]
    return ans
        
for j in range(K + 1):
    dp[0][j] = 1
for i in range(1, N + 1):
    for j in range(1, K + 1):
        if j == 1:
            dp[i][j] = 1
        else:
            dp[i][j] = sumf(i, j)
            dp[i][j] %= 1000000000
print(dp[N][K])
# print("test")
# for i in range(N + 1):
#     for j in range(K + 1):
#         print(dp[i][j], end=" ")
#     print()